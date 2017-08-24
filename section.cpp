#include "section.h"

Section::Section()
{
    r_ = 0.2;
    b_ = 120;
    airfoil_ = Airfoil();
}

SectionData* glouert(const Section &section, const Air &air, float wind, float rotationSpeed)
{
    float a = 1.0/3.0;
    float a_= 0;

    float lambda = rotationSpeed ;
    float sigma = ;

    //Решение нелинейной системы итерациями
    for( int i = 0; i<10; i++){
        float fi = atan( (1-a)/(1+a_)/lambda );
        float cy = ;
        float mu = ;
        float fPr = M_PI_2*acos( exp(-B/2*(1-r_)/r_/sin(fi)) );

        a = 1 / ( 4*fPr*pow(sin(fi), 2) / (sigma*cy*(cos(fi) + mu*sin(fi))) + 1  );
        a_ = 1 / ( 4*fPr*sin(fi)*cos(fi) / (sigma*cy*(sin(fi) - mu*cos(fi))) + 1  );
    }

    SectionData* data = new SectionData();

    return data;
}
