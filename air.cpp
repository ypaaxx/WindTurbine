#include "air.h"
#include <math.h>

/** Стандартный конструктор с параметрами воздуха при н.у.*/
Air::Air()
{
    // По умолчанию среда задается свойствами воздуха при 15C
    // Это пиздец как важно
    setTemperature(288.15);//(K)
    setDensity(1.225);//(kg/m^3)
    setViscosity(1.47e-5);//(m^2/s)
}

/** Вязкость и плотность определяются температурой */
Air::Air(float const temperature)
{
    float R = 287;// (J/kg/K)
    float pressure_ = 101325;// (K)
    setTemperature(temperature);
    setDensity(pressure_/temperature/R);
    float C = 120;//(K) Постоянная Сазерланда
    float T_0 = 291.15;//(K) Контрольная температура
    float Mu_0 = 18.27e6;//(Pa*s) Контрольная вязкость
    setViscosity(Mu_0 * (T_0 + C)/(temperature + C)*pow(temperature/T_0, 1.5)/getDensity());
}

/** Выставление плотности*/
void Air::setDensity(float density)
{
    density_ = density;
}

/** Выставление кинематической вязкости */
void Air::setViscosity(float viscosity)
{
    viscosity_ = viscosity;
}

/** Выставление температуры */
void Air::setTemperature(float temperature)
{
    temperature_ = temperature;
}

/** Выдача плотности */
float Air::getDensity()
{
    return density_;
}

/** Выдача вязкости */
float Air::getViscosity()
{
    return viscosity_;
}

/** Выдача температуры */
float Air::getTemperature()
{
    return temperature_;
}
