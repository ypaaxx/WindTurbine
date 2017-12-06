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
    inline float density() const { return density_;}
    inline float viscosity() const { return viscosity_;}
    inline float temperature() const { return temperature_;}
    inline float pressure() const { return pressure_;}

    inline float rho() const { return density();}
    inline float v() const { return viscosity();}
    inline float T() const { return temperature();}
    inline float P() const { return pressure();}

private:
    float const GAS_CONST = 287; // (J/kg/K)
    float const K = 1.4; 
    float density_;
    float viscosity_;
    float temperature_;
    float pressure_;
};

#endif // AIR_H
