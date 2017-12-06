#ifndef ROTOR_H
#define ROTOR_H

#include <vector>
#include "section.h"

class Rotor
{
public:
    Rotor();
    int getNumerBlades() const;
    void setNumerBlades(int value);

    float getR_tip() const
    {
        return R_tip;
    }
    void setR_tip(float value);

private:
    int numerBlades;
    float R_tip;
    float R_hub;

    std::vector <void*> *blade;
};

#endif // ROTOR_H
