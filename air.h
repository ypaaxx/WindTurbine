#ifndef AIR_H
#define AIR_H

/** Сие класс есть модель сухого воздуха */

class Air
{
public:
    Air();
    Air(double);
    Air(double, double);

    /** Выставление параметров */
    void setDensity(double const density) { density_ = density;}
    void setViscosity(double const viscosity) { viscosity_ = viscosity;}
    void setTemperatureC(double const temperatureC) { temperature_ = 273.15 + temperatureC;}
    void setPressure(double const pressure) { pressure_ = pressure;}

    /** Возращение параметров */
    inline double density() const { return density_;}
    inline double viscosity() const { return viscosity_;}
    inline double temperature() const { return temperature_;}
    inline double pressure() const { return pressure_;}

    inline double rho() const { return density();}
    inline double v() const { return viscosity();}
    inline double T() const { return temperature();}
    inline double P() const { return pressure();}

private:
    double const GAS_CONST = 287; // (J/kg/K)
    double const K = 1.4;
    double density_;
    double viscosity_;
    double temperature_;
    double pressure_;
};

#endif // AIR_H
