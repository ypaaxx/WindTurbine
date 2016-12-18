#include "airfoil.h"
#include <iostream>
#include <fstream>

Airfoil::Airfoil()
{


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

/** Выдача коэффициента подьемной силы Cl */
float Airfoil::getCl(float reynolds, float mach, float alpha) const
{
    return 0;
}


