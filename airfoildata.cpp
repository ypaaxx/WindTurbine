#include "airfoildata.h"
#include <map>
#include <iostream>

/** Cодержащий точки характеристики профиля
 * по фиксированным числам Рейнольдса и Маха */
AirfoilData::AirfoilData()
{
    // S822 Re=600000;
    addPoint(-3, -0.04, 0.0076, -0.0746);
    addPoint(-2, 0.068, 0.0072, -0.0772);
    addPoint(-1, 0.176, 0.0072, -0.0798);
    addPoint(0, 0.284, 	0.0073, -0.0823);
    addPoint(1, 0.391, 	0.0075, -0.0845);
    addPoint(2, 0.497, 0.0077, -0.0866);
    addPoint(3, 0.602, 0.008, -0.0885);
    addPoint(4, 0.707, 0.0083, -0.0903);
    addPoint(5, 0.811, 0.0087, -0.0917);
    addPoint(6, 0.911, 0.0092, -0.0924);
    addPoint(7, 0.964, 0.0167, -0.0836);
    addPoint(8, 1.044, 0.0189, -0.0809);
}

/** Добавления новой точки во внутренний класс*/
void AirfoilData::addPoint(float alpha, float cl, float cd, float cm)
{
    //alpha_.push_back(alpha);
    cl_.insert(std::pair <float, float> (alpha, cl));
    cd_.insert(std::pair <float, float> (alpha, cd));
    cm_.insert(std::pair <float, float> (alpha, cm));
}

/** Получение коэффициента подьемной силы Cl по углу атаки */
float AirfoilData::getCl(float alpha)
{
    std::map<float,float>::iterator it=cl_.find(alpha);
    if (it != cl_.end()) return cl_.at(alpha);

    std::map<float,float>::iterator  p1 = cl_.lower_bound(alpha);
    std::map<float,float>::iterator  p2 = cl_.upper_bound(alpha);

    std::cout << p1->first << ":" << p1->second << std::endl;

    return p1->second;
}
