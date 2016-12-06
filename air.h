#ifndef AIR_H
#define AIR_H


class Air
{
public:
    Air();
    Air(float);

    void setDensity(float);
    void setViscosity(float);
    void setTemperature(float);
    void setPressure(float);


    float getDensity();
    float getViscosity();
    float getTemperature();
    float getPressure();

private:
    float density_;
    float viscosity_;
    float temperature_;
    float pressure_;
};

#endif // AIR_H
