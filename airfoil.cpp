#include "airfoil.h"

#include <fstream>

Airfoil::Airfoil()
{
    std::cout << "hi! I am the new airfoil!" << std::endl;
}

Airfoil::Airfoil(const char* file)
{
    std::ifstream input;
    input.open(file, std::fstream::in);

    if (input.is_open()) std::cout << file << " is open" <<  std::endl;
    else {
        std::cerr << file << " can't open" <<  std::endl;
    }

    char tmp[100];
    while (input.getline(tmp, 100)){
        std::cout << tmp << std::endl;
    }
}

/** Чего толку подписывать деструктор */
Airfoil::~Airfoil()
{
    std::cout << "Oh, no! I'm dying! Wha-a-a-y?" << std::endl;
}

/** Выставление наименования профиля */
void Airfoil::setName(std::string name)
{
    name_ = name;
}

/** Выставление максимальной толщины профиля */
void Airfoil::setThickness(float thickness)
{
    thickness_ = thickness;
}

/** Добавление точки характеристики */
void Airfoil::addPoint(float reynolds, float mach, float alpha, float cl, float cd, float cm)
{
    if (airfoilDataRe.find(reynolds) != airfoilDataRe.end()) {
        airfoilDataRe.at(reynolds).addPoint(alpha, cl, cd, cm);
    } else {
        AirfoilData tmpAirfoilData = AirfoilData();
        tmpAirfoilData.setMach(mach);
        tmpAirfoilData.setReynolds((int) reynolds);

        tmpAirfoilData.addPoint(alpha, cl, cd, cm);

        airfoilDataRe.insert(std::pair <float, AirfoilData> (reynolds, tmpAirfoilData));
        //airfoilDataM.insert(std::pair <float, AirfoilData&> (reynolds, tmpAirfoilData));
    }
}

/** Выдача Коэффициента подьемной силы Cl */
float Airfoil::getCl(float reynolds, float mach, float alpha)
{
    return airfoilDataRe.at(reynolds).getCl(alpha);
}

/** Внутренний класс содержащий точки характеристики профиля
 * по фиксированным числам Рейнольдса и Маха */
Airfoil::AirfoilData::AirfoilData()
{

}

/** Выставление числа Рейнольдса */
void Airfoil::AirfoilData::setReynolds(int reynolds)
{
    reynolds_ = reynolds;
}

/** Выставление числа Маха */
void Airfoil::AirfoilData::setMach(float mach)
{
    mach_=mach;
}

/** Добавления новой точки во внутренний класс*/
void Airfoil::AirfoilData::addPoint(float alpha, float cl, float cd, float cm)
{
    //alpha_.push_back(alpha);
    cl_.insert(std::pair <float, float> (alpha, cl));
    cd_.insert(std::pair <float, float> (alpha, cd));
    cm_.insert(std::pair <float, float> (alpha, cm));
}

/** Получение коэффициента подьемной силы Cl по углу атаки */
float Airfoil::AirfoilData::getCl(float alpha)
{
    std::map<float,float>::iterator it=cl_.find(alpha);
    if (it != cl_.end()) return cl_.at(alpha);

    std::map<float,float>::iterator  p1 = cl_.lower_bound(alpha);
    std::map<float,float>::iterator  p2 = cl_.upper_bound(alpha);

    std::cout << p1->first << ":" << p1->second << std::endl;

    return p1->second;
}


