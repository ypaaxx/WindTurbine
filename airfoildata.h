#ifndef AIRFOILDATA_H
#define AIRFOILDATA_H

/**
 * Класс содержит продувку профиля на определенных числах Маха и Рейнольдса
*/

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <mymath.h>

class AirfoilData
{
public:
    /* Какойто бестолковый стандартный профиль */
    AirfoilData();
    /* По имени файла из которого всё будет выдёргиваться */
    AirfoilData(std::string fileName);
    AirfoilData(float);
    AirfoilData(float, float);

    void setReynolds(int const reynolds) { reynolds_ = reynolds;}
    void setMach(float const mach) { mach_ = mach;}
    float getReynolds() const { return reynolds_; }
    float getMach() const { return mach_; }

    void addPoint(float alpha, float cl, float cd, float cm);
    void addPoint(float alpha, float cl, float cd);
    void addCl(float alpha, float cl);
    void addCd(float alpha, float cd);
    void addCm(float alpha, float cm);

    void makeInterpolant();

    float getCl(const float);
    float getCd(const float);
    float getCm(const float);

    void inintiateMinMax();

private:
    int reynolds_; //число Рейнольдса
    float mach_; //число Маха

    std::vector<Point*> *cl_;
    std::vector<Point*> *cd_;
    std::vector<Point*> *cm_;

    double maxAlpha;
    double minAlpha;

    double getSome(std::vector<Point*> *some, const double alpha) const;
};

AirfoilData reynoldsInterpolatedData(const AirfoilData firstData, const AirfoilData secondData, double reynolds);

#endif // AIRFOILDATA_H
