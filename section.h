#ifndef SECTION_H
#define SECTION_H
#include "airfoil.h"

class Section : public Airfoil
{
public:
    Section();
private:
    float r_;
    float b_;

};

#endif // SECTION_H
