#ifndef AIR_H
#define AIR_H

/** Сие класс есть модель сухого воздуха */
class Air
{
public:
    Air();
    Air(float);
    Air(float, float);

    /** Выставление параметров */
    void setDensity(float const density) { density_ = density;}
    void setViscosity(float const viscosity) { viscosity_ = viscosity;}
    void setTemperature(float const temperature) { temperature_ = temperature;}
    void setPressure(float const pressure) { pressure_ = pressure;}

    /** Возращение параметров */
    inline float getDensity() const { return density_;}
    inline float getViscosity() const { return viscosity_;}
    inline float getTemperature() const { return temperature_;}
    inline float getPressure() const { return pressure_;}

    inline float rho() const { return getDensity();}
    inline float v() const { return getViscosity();}
    inline float T() const { return getTemperature();}
    inline float P() const { return getPressure();}

private:
    float const GAS_CONST = 287; // (J/kg/K)
    float density_;
    float viscosity_;
    float temperature_;
    float pressure_;
};

#endif // AIR_H
