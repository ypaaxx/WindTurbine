#include "airfoildata.h"
#include <map>
#include <iostream>

/** Cодержащий точки характеристики профиля
 * по фиксированным числам Рейнольдса и Маха */
AirfoilData::AirfoilData()
{
    
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
