#ifndef AIRFOILDATA_H
#define AIRFOILDATA_H

/**
 * Класс содержит продувку профиля на определенных числах Маха и Рейнольдса
*/

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include "mymath.h"

class AirfoilData
{
public:
    /* Какойто бестолковый стандартный профиль */
    AirfoilData();
    /* По имени файла из которого всё будет выдёргиваться */
    AirfoilData(std::string fileName);
    AirfoilData(double);
    AirfoilData(double, double);

    void setReynolds(int const reynolds) { reynolds_ = reynolds;}
    void setMach(double const mach) { mach_ = mach;}
    double getReynolds() const { return reynolds_; }
    double getMach() const { return mach_; }

    void addPoint(double alpha, double cl, double cd, double cm);
    void addPoint(double alpha, double cl, double cd);
    void addCl(double alpha, double cl);
    void addCd(double alpha, double cd);
    void addCm(double alpha, double cm);

    void makeInterpolant();

    double getCl(const double alpha);
    double getCd(const double alpha);
    double getCm(const double alpha);

    double getMu(double alpha);
    double getMaxMuAlpha(){
        if (initiatedMinMax == false) {
            inintiateMinMax();
        }
        return maxMuAlpha;
    }

    void inintiateMinMax();

private:
    int reynolds_; //число Рейнольдса
    double mach_; //число Маха

    std::vector<Point*> *cl_;
    std::vector<Point*> *cd_;
    std::vector<Point*> *cm_;
    double getSome(std::vector<Point*> *some, const double alpha);

    double maxAlpha;
    double minAlpha;
    double maxMuAlpha;

    bool initiatedMinMax = 0;

};

AirfoilData reynoldsInterpolatedData(const AirfoilData firstData, const AirfoilData secondData, double reynolds);

#endif // AIRFOILDATA_H
