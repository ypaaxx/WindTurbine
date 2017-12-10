#include "airfoil.h"
#include <iostream>
#include <fstream>
#include <algorithm>

Airfoil::Airfoil()
{
    //name_ = "s822";

}

/** Создаёт обьект по данным из файла какого-то там */
Airfoil::Airfoil(const char* file)
{
    //Оставим пока так
}

Airfoil::~Airfoil()
{

}

/** Добавление точки характеристики */
void Airfoil::addPoint(double reynolds, double mach, double alpha, double cl, double cd, double cm)
{
/*
    auto result = std::find(numerReynolds.begin(), numerReynolds.end(), reynolds);
    if( result != numerReynolds.end() ) airfoilDataRe.addPoint(alpha, cl, cd, cm);
    else {

        AirfoilData tmpAirfoilData = AirfoilData();
        tmpAirfoilData.setMach(mach);
        tmpAirfoilData.setReynolds((int) reynolds);
        tmpAirfoilData.addPoint(alpha, cl, cd, cm);

    }
*/
/*
    if (airfoilDataRe.find(reynolds) != airfoilDataRe.end()) {
        airfoilDataRe.at(reynolds).addPoint(alpha, cl, cd, cm);
    } else {
        AirfoilData tmpAirfoilData = AirfoilData();
        tmpAirfoilData.setMach(mach);
        tmpAirfoilData.setReynolds((int) reynolds);

        tmpAirfoilData.addPoint(alpha, cl, cd, cm);

        //airfoilDataRe.insert(std::pair <double, AirfoilData> (reynolds, tmpAirfoilData));
        //airfoilDataM.insert(std::pair <double, AirfoilData&> (reynolds, tmpAirfoilData));
    }
*/
}

void Airfoil::addPoint(double alpha, double cl, double cd)
{
    //Создание рейнольдса по умолчанию, если изначально список пуст
    if ( airfoilDataRe_.empty()){
        AirfoilData *tmpAirfoilData = new AirfoilData;
        airfoilDataRe_.push_back(tmpAirfoilData);
        setDefaultData(*tmpAirfoilData);
    }
    defaultData_->addPoint(alpha, cl, cd);
}

/** Выдача коэффициента подьемной силы Cl */
double Airfoil::getCl(double Re, double M, double alpha) const
{
    // Это всё блаж, мечты, мы махом пока принебрежем
    return 0;
}

double Airfoil::getCl(double Re, double alpha) const
{
    return 0;
}

double Airfoil::getCl(double alpha) const
{
    return defaultData_->getCl(alpha);
}

double Airfoil::getCd(double alpha) const
{
    return defaultData_->getCd(alpha);
}

AirfoilData *Airfoil::data(double Re)
{
    if (Re == 0)
        return defaultData_;
}

