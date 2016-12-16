#include "section.h"

Section::Section()
{
    r_ = 0.2;
    b_ = 120;
    airfoil_ = Airfoil();
}

float glouert(const Section &section, const Air &air, SectionData &target)
{
    float a = 1.0/3.0;
    float a_= 0;


    return a;
}
