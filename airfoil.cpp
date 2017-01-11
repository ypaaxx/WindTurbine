#include "airfoil.h"
#include <iostream>
#include <fstream>
#include <algorithm>

Airfoil::Airfoil()
{
    //name_ = "s822";

}

Airfoil::Airfoil(const char* file)
{
    //Оставим пока так
}

/** Чего толку подписывать деструктор */
Airfoil::~Airfoil()
{
    std::cout << "Oh, no! I'm dying! Wha-a-a-y?" << std::endl;
}

/** Добавление точки характеристики */
void Airfoil::addPoint(float reynolds, float mach, float alpha, float cl, float cd, float cm)
{
    auto result = std::find(airfoilDataRe.begin(), airfoilDataRe.end(), reynolds);
    if(std::find(airfoilDataRe.begin(), airfoilDataRe.end(), reynolds));
/*
    if (airfoilDataRe.find(reynolds) != airfoilDataRe.end()) {
        airfoilDataRe.at(reynolds).addPoint(alpha, cl, cd, cm);
    } else {
        AirfoilData tmpAirfoilData = AirfoilData();
        tmpAirfoilData.setMach(mach);
        tmpAirfoilData.setReynolds((int) reynolds);

        tmpAirfoilData.addPoint(alpha, cl, cd, cm);

        //airfoilDataRe.insert(std::pair <float, AirfoilData> (reynolds, tmpAirfoilData));
        //airfoilDataM.insert(std::pair <float, AirfoilData&> (reynolds, tmpAirfoilData));
*/
    }
}

/** Выдача коэффициента подьемной силы Cl */
float Airfoil::getCl(float reynolds, float mach, float alpha) const
{
    // Это всё блаж, мечты, мы махом пока принебрежем
    return 0;
}

float Airfoil::getCl(float reynolds, float alpha) const
{

    return 0;
}

float Airfoil::getCl(float alpha) const
{

    return 0;
}

