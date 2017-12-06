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
    setPressure(101325);//(Pa)
}

/** Параметры воздуха от температуры и давления */
Air::Air(float const temperature, float const pressure)
{
    setPressure(pressure);//(Pa)
    setTemperature(temperature);
    setDensity(Air::pressure()/temperature/GAS_CONST);
    float C = 120;//(K) Постоянная Сазерланда
    float T_0 = 291.15;//(K) Контрольная температура
    float Mu_0 = 18.27e-6;//(Pa*s) Контрольная динамическая вязкость
    setViscosity(Mu_0 * (T_0 + C) / (temperature + C) * pow(temperature/T_0, 1.5) / density());
}

/** Вязкость и плотность определяются температурой */
Air::Air(float const temperature)
{
    if ((temperature < 200) || (temperature > 2500)) // чёт не работает
        throw 1;//Bad_air();

    setTemperature(temperature);
    setPressure(101325);//(Pa)
    setDensity(pressure()/temperature/GAS_CONST);
    float C = 120;//(K) Постоянная Сазерланда
    float T_0 = 291.15;//(K) Контрольная температура
    float Mu_0 = 18.27e-6;//(Pa*s) Контрольная динамическая вязкость
    setViscosity(Mu_0 * (T_0 + C) / (temperature + C) * pow(temperature/T_0, 1.5) / density());
}
