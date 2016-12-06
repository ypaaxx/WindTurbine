#ifndef FLUID_H
#define FLUID_H


class Fluid
{
public:
    Fluid();

    void setDensity(float);
    void setViscosity(float);
    void setTemperature(float);

    float getDensity();
    float getViscosity();
    float getTemperature();

private:
    float density_;
    float viscosity_;
    float temperature_;
};

#endif // FLUID_H
