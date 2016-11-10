#include "airfoil.h"

Airfoil::Airfoil()
{
    std::cout << "hi! I am the new airfoil!" << std::endl;
}

Airfoil::~Airfoil()
{
    std::cout << "Oh, no! I'm daing! Wha-a-a-y?" << std::endl;
}

/* Конструктор загружающий данные из файла */
Airfoil::Airfoil(std::string nameFile)
{
    std::cout << nameFile << std::endl;
}

/* Добавления новой точки во внутренний класс*/
void Airfoil::AirfoilData::addPoint(float alpha, float cl, float cd, float cm)
{
    alpha_.push_back(alpha);
    cl_.push_back(cl);
    cd_.push_back(cd);
    cm_.push_back(cm);
}


