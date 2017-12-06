#include "section.h"

Section::Section(Rotor *rotor, float r, float tetta, float b, Airfoil *airfoil)
{
    rotor_ = rotor;
    r_ = r;
    tetta_ = tetta;
    b_ = b;
    airfoil_ = airfoil;
}

SectionData* Section::glouert(const Air &air, float windSpeed, float rpm)
{
    float R_tip = rotor_->getR_tip();
    float a = 1.0/3.0;
    float a_= 0;
    float fPr;
    float fi;

    float lambda = (rpm*2*M_PI/60)*R_tip*r_/windSpeed ; //Сюда добавить радиус колеса
    int B = rotor_->getNumerBlades();
    float sigma = B * b_ / 2 / M_PI / r_;

    //Решение нелинейной системы итерациями
    for( int i = 0; i<10; i++){
        fi = atan( (1-a)/(1+a_)/lambda );
        float attack = fi - tetta_;
        float cy = airfoil_->getCl(attack);
        float mu = airfoil_->getCd(attack) / cy;
        fPr = M_PI_2*acos( exp(-B/2*(1-r_)/r_/sin(fi)) );

        a = 1 / ( 4*fPr*pow(sin(fi), 2) / (sigma*cy*(cos(fi) + mu*sin(fi))) + 1  );
        a_ = 1 / ( 4*fPr*sin(fi)*cos(fi) / (sigma*cy*(sin(fi) - mu*cos(fi))) + 1  );
    }

    SectionData* data = new SectionData();

    float Re = air.viscosity()*b_*windSpeed/air.density();
    float dMdR= 4*M_PI*air.density()*pow(r_*R_tip*windSpeed, 2)*lambda*a_*(1-a)*fPr;
    float dTdR= 4*M_PI*air.density()*r_*R_tip*pow(windSpeed, 2)*a*(1-a)*fPr;

    data->setA(a);
    data->setA2(a_);
    data->setFi(fi);
    data->set_dMdr(dMdR);
    data->set_dTdr(dTdR);

    return data;
}
