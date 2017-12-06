#include "rotor.h"

Rotor::Rotor()
{

}

int Rotor::getNumerBlades() const
{
    return numerBlades;
}

void Rotor::setNumerBlades(int value)
{
    numerBlades = value;
}



void Rotor::setR_tip(float value)
{
    R_tip = value;
}
