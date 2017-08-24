#ifndef AIRFOILDATA_H
#define AIRFOILDATA_H

/* Класс содержит продувку профиля на определенных числах Маха и Рейнольдса */

#include <vector>
#include <string>
#include <fstream>
#include <libalglib/interpolation.h>

class AirfoilData
{
public:
    /* Какойто бестолковый стандартный профиль */
    AirfoilData();
    /* По имени файла из которого всё будет выдёргиваться */
    AirfoilData(std::string file);
    AirfoilData(float);
    AirfoilData(float, float);

    void setReynolds(int const reynolds) { reynolds_ = reynolds;}
    void setMach(float const mach) { mach_ = mach;}
    float getReynolds() const { return reynolds_; }
    float getMach() const { return mach_; }

    void addPoint(float alpha, float cl, float cd, float cm);
    void addPoint(float alpha, float cl, float cd);

    void makeInterpolant();

    float getCl(float);
    float getCd(float);
    float getCm(float);

    void inintiateMinMax();

private:
    int reynolds_; //число Рейнольдса
    float mach_; //число Маха

    std::vector<double> alpha_;
    std::vector<double> cl_;
    std::vector<double> cd_;
    std::vector<double> cm_;

    double maxAlpha;
    double minAlpha;

    alglib::real_1d_array alg_alpha_, alg_cl_, alg_cd_, alg_cm_; // массивы указателей
    alglib::spline1dinterpolant sl_, sd_, sm_; // коэффициенты интерполяции

};

AirfoilData reynoldsInterpolatedData(const AirfoilData firstData, const AirfoilData secondData, double reynolds);

#endif // AIRFOILDATA_H
