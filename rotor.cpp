#include "rotor.h"
#include <iostream>

Rotor::Rotor(int numberOfBlades, double R_tip, double R_hub){
    numberBlades = numberOfBlades;
    rTip = R_tip;
    rHub = R_hub;
    blade = new std::vector <Section*>;
}

std::vector<SectionData *> *Rotor::glouert(const Air *air, double windSpeed, double rpm)
{
    std::vector<SectionData*> *data = new std::vector<SectionData*> (blade->size());
    for(Section *section:*blade){
        data->push_back(section->glouert(air, windSpeed, rpm));
    }
    return data;
}

Section::Section(Rotor *rotor, double r, double tetta, double b, Airfoil *airfoil)
{
    rotor_ = rotor;
    r_ = r;
    tetta_ = tetta;
    b_ = b;
    airfoil_ = airfoil;
}

Section::Section(Rotor *rotor, Airfoil *airfoil, double lambda, double r)
{
    airfoil_ = airfoil;
    rotor_ = rotor;
    r_=r;
    double B = rotor->getNumerBlades();

    double attack = airfoil->data()->getMaxMuAlpha();

    double mu = airfoil->getCd(attack)/airfoil->getCl(attack);

    auto a2 = [&](double a){return (-(lambda + mu) + sqrt( pow(lambda + mu, 2) - 4*a*(a+mu*lambda-1) ))/2/lambda;};
    auto fi = [&](double a){return atan( (1-a)/(1+a2(a))/lambda );};
    auto fPr = [&](double a){return M_PI_2*acos( exp(-B/2*(1-r_)/r_/sin(fi(a))) );};

    auto targetForOpt = [&](double a){return (1-a)*a2(a)*fPr(a);};

    //Поиск оптимальных а
    //Метод золотого сечения

    double  delta = 0.0005; //точность
    double f = 0.5 + sqrt(5)/2;

    double start = 0.0;
    double finish = 0.6;

    Point Start(start);
    Point Finish(finish);

    double x1 = finish-(finish-start)/f;
    double x2 = start+(finish-start)/f;
    Point p1( x1, targetForOpt( x1 ) );
    Point p2( x2, targetForOpt( x2 ) );

    do{
        if ( Point::comparationY(&p1, &p2)){
            Start = p1;
            p1 = p2;
            p2.setX(Start.x()+(Finish.x()-Start.x())/f);
            p2.setY(targetForOpt(p2.x()));

        } else {
            Finish = p2;
            p2 = p1;
            p1.setX(Finish.x()-(Finish.x()-Start.x())/f);
            p1.setY(targetForOpt(p1.x()));
        }

    }while( fabs(Finish.x() - Start.x()) > delta);

   double a_opt = (Start.x() + Finish.x())/2;
   double a2_opt = a2(a_opt);
   double sigma_opt = 4*fPr(a_opt)*pow(sin(fi(a_opt)),2)*a_opt/
           (airfoil_->getCl(attack)*cos(fi(a_opt)) + airfoil_->getCd(attack)*sin(fi(a_opt)))/(1-a_opt);
   double h_opt = 2*M_PI*r_*sigma_opt/B;

   setChord(h_opt);
   setTetta(fi(a_opt) - attack*M_PI/180);
}

SectionData* Section::glouert(const Air *air, double windSpeed, double rpm)
{
    double R_tip = rotor_->getR_tip();
    double a = 1.0/3.0;
    double a2_= 0;
    double fPr;
    double fi;
    double attack;

    double lambda = (rpm*2*M_PI/60)*R_tip*r_/windSpeed ; //Сюда добавить радиус колеса
    int B = rotor_->getNumerBlades();
    double sigma = B * b_ / 2 / M_PI / r_;

    //Решение нелинейной системы итерациями
    for( int i = 0; i<10; i++){
        fi = atan( (1-a)/(1+a2_)/lambda );
        attack = fi - (tetta_)*M_PI/180;
        double cy, mu;
        try{
            cy = airfoil_->getCl(attack);
            mu = airfoil_->getCd(attack) / cy;
        }catch(...){
            std::cout << "Нет данных для угла аттаки:" << attack << std::endl;
        }
        fPr = M_PI_2*acos( exp(-B/2*(1-r_)/r_/sin(fi)) );

        a = 1 / ( 4*fPr*pow(sin(fi), 2) / (sigma*cy*(cos(fi) + mu*sin(fi))) + 1  );
        a2_ = 1 / ( 4*fPr*sin(fi)*cos(fi) / (sigma*cy*(sin(fi) - mu*cos(fi))) + 1  );
    }

    SectionData* data = new SectionData();

    double Re = air->viscosity()*b_*windSpeed/air->density();
    double dMdR= 4*M_PI*air->density()*pow(r_*R_tip*windSpeed, 2)*lambda*a2_*(1-a)*fPr;
    double dTdR= 4*M_PI*air->density()*r_*R_tip*pow(windSpeed, 2)*a*(1-a)*fPr;

    data->setA(a);
    data->setA2(a2_);
    data->setFi(fi);
    data->set_dMdr(dMdR);
    data->set_dTdr(dTdR);
    data->setAttack(attack);

    return data;
}

SectionData::SectionData()
{

}
/*
Rotor *newRotor(const Condition &condition, int numberOfBlades, double power)
{
    double cp = 0.3;
    double rTip = sqrt(power*2/M_PI/air.density()/pow(windSpeed, 3));
    double rHub = 0.17 * rTip;
    Rotor *rotor = new Rotor(numberOfBlades, rTip, rHub);

    double a = 1.0/3.0;
    double a2_= 0;
    double fPr;
    double fi;
    double attack = 4;

    double lambda = (rpm*2*M_PI/60)*rTip*r_/windSpeed ; //Сюда добавить радиус колеса

    double cy = airfoil_->getCl(attack);
    double mu = airfoil_->getCd(attack) / cy;

    auto aOpt = []{
        auto fi_ = [](double a, double a2, double lambda){ return (1-a)/(a2+1)/lambda;};
        auto fPr_ = [] (double a, ) { return M_PI_2*acos( exp(-B/2*(1-r_)/r_/sin(fi))};
    };
    int B = rotor_->getNumerBlades();
    double sigma = B * b_ / 2 / M_PI / r_;

    //Решение нелинейной системы итерациями
    for( int i = 0; i<10; i++){
        fi = atan( (1-a)/(1+a2_)/lambda );
        attack = fi - (tetta_)*M_PI/180;

        }catch(...){
            std::cout << "Нет данных для угла аттаки:" << attack << std::endl;
        }
        fPr = M_PI_2*acos( exp(-B/2*(1-r_)/r_/sin(fi)) );

        a = 1 / ( 4*fPr*pow(sin(fi), 2) / (sigma*cy*(cos(fi) + mu*sin(fi))) + 1  );
        a2_ = 1 / ( 4*fPr*sin(fi)*cos(fi) / (sigma*cy*(sin(fi) - mu*cos(fi))) + 1  );
    }

    auto dMdr = [&]{ return 4*M_PI*air.density()*pow(r_*rTip*windSpeed, 2)*lambda*a2_*(1-a)*fPr; };
    return rotor;
}
*/

Condition::Condition( Air *air, double windSpeed, double rpm)
{
    air_ = air;
    windSpeed_ = windSpeed;
    rpm_ = rpm;
}
