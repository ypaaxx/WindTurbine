#include "air.h"
#include <math.h>

/** Стандартный конструктор с параметрами воздуха при н.у.*/
Air::Air()
{
    // По умолчанию среда задается свойствами воздуха при 15C
    // Это пиздец как важно
    setTemperatureC(15);//(K)
    setDensity(1.225);//(kg/m^3)
    setViscosity(1.47e-5);//(m^2/s)
    setPressure(101325);//(Pa)
}

/** Параметры воздуха от температуры и давления */
Air::Air(double const temperatureC, double const pressure)
{
    setPressure(pressure);//(Pa)
    setTemperatureC(temperatureC);
    if ((temperature() < 0) || (temperature() > 555)) // выкидывет при выходе за пределы 10% погрешности ф-лы Сазерленда
        if (pressure_ > 3.45e6)
            throw 0;//Bad_air();
    setDensity(Air::pressure()/temperature()/GAS_CONST);
    double C = 120;//(K) Постоянная Сазерланда
    double T_0 = 291.15;//(K) Контрольная температура
    double Mu_0 = 18.27e-6;//(Pa*s) Контрольная динамическая вязкость
    setViscosity(Mu_0 * (T_0 + C) / (temperature() + C) * pow(temperature()/T_0, 1.5) / density());
}

/** Вязкость и плотность определяются температурой */
Air::Air(double const temperatureC)
{
    setTemperatureC(temperatureC);
    setPressure(101325);//(Pa)

    if ((temperature() < 0) || (temperature() > 555)) // чёт не работает
        throw 0;//Bad_air();

    setDensity(pressure()/temperature()/GAS_CONST);
    double C = 120;//(K) Постоянная Сазерланда
    double T_0 = 291.15;//(K) Контрольная температура
    double Mu_0 = 18.27e-6;//(Pa*s) Контрольная динамическая вязкость
    setViscosity(Mu_0 * (T_0 + C) / (temperature() + C) * pow(temperature()/T_0, 1.5) / density());
}
