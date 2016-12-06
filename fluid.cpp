#include "fluid.h"

/** Стандартный конструктор с параметрами воздуха при н.у.*/
Fluid::Fluid()
{
    setTemperature(288.15);//(K)
    setDensity(1.225);//(kg/m^3)
    setViscosity(1.47e-5);//(m^2/s)
}

/** Выставление плотности*/
void Fluid::setDensity(float density)
{
    density_ = density;
}

/** Выставление кинематической вязкости */
void Fluid::setViscosity(float viscosity)
{
    viscosity_ = viscosity;
}

/** Выставление температуры */
void Fluid::setTemperature(float temperature)
{
    temperature_ = temperature;
}

/** Выдача плотности */
float Fluid::getDensity()
{
    return density_;
}

/** Выдача вязкости */
float Fluid::getViscosity()
{
    return viscosity_;
}

/** Выдача температуры */
float Fluid::getTemperature()
{
    return temperature_;
}
