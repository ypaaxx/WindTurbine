#include "section.h"

Section::Section()
{
    r_ = 0.2;
    b_ = 0.1;
    tetta_ = 30 * M_PI/180;
    numerBlades_ = 3;
    airfoil_ = Airfoil();
}

SectionData* Section::glouert(const Air &air, float wind, float rotationSpeed)
{
    float a = 1.0/3.0;
    float a_= 0;

    float lambda = rotationSpeed ;
    int B = numerBlades_;
    float sigma = B * b_ / 2 / M_PI / r_;

    //Решение нелинейной системы итерациями
    for( int i = 0; i<10; i++){
        float fi = atan( (1-a)/(1+a_)/lambda );
        float attack = fi - tetta_;
        float cy = airfoil_.getCl(attack);
        float mu = airfoil_.getCd(attack) / cy;
        float fPr = M_PI_2*acos( exp(-B/2*(1-r_)/r_/sin(fi)) );

        a = 1 / ( 4*fPr*pow(sin(fi), 2) / (sigma*cy*(cos(fi) + mu*sin(fi))) + 1  );
        a_ = 1 / ( 4*fPr*sin(fi)*cos(fi) / (sigma*cy*(sin(fi) - mu*cos(fi))) + 1  );
    }

    SectionData* data = new SectionData();

    return data;
}
