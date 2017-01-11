#ifndef AIRFOILDATA_H
#define AIRFOILDATA_H

#include <vector>
#include <libalglib/interpolation.h>

class AirfoilData
{
public:
    AirfoilData();
    AirfoilData(float);
    AirfoilData(float, float);

    void setReynolds(int const reynolds) { reynolds_ = reynolds;}
    void setMach(float const mach) { mach_ = mach;}

    void addPoint(float, float, float, float);

    void makeInterpolant();

    float getCl(float);
    float getCd(float);
    float getCm(float);

    float getReynolds() const { return reynolds_; }
    float getMach() const { return mach_; }

    void inintiateMinMax();

private:
    int reynolds_; //число Рейнольдса
    float mach_; //число Маха

    double maxAlpha;
    double minAlpha;

    std::vector<double> alpha_;
    std::vector<double> cl_;
    std::vector<double> cd_;
    std::vector<double> cm_;

    alglib::real_1d_array alg_alpha_, alg_cl_, alg_cd_, alg_cm_; // массивы указателей
    alglib::spline1dinterpolant sl_, sd_, sm_; // коэффициенты интерполяции

};

AirfoilData reynoldsInterpolatedData(const AirfoilData firstData, const AirfoilData secondData, double reynolds);

#endif // AIRFOILDATA_H
