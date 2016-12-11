#ifndef AIRFOILDATA_H
#define AIRFOILDATA_H

#include <map>

class AirfoilData
{
public:
    AirfoilData();
    AirfoilData(float);
    AirfoilData(float, float);

    void setReynolds(int const reynolds) { reynolds_ = reynolds;}
    void setMach(float const mach) { mach_ = mach;}

    void addPoint(float, float, float, float);

    float getCl(float);
    float getCd(float);
    float getCm(float);

private:
    int reynolds_; //число Рейнольдса
    float mach_; //число Маха
    std::map <float, float> cl_;
    std::map <float, float> cd_;
    std::map <float, float> cm_;
};

#endif // AIRFOILDATA_H
