#include "airfoil.h"

Airfoil::Airfoil()
{
    std::cout << "hi, new airfoil" << std::endl;
}

/* Конструктор загружающий данные из файла */
Airfoil::Airfoil(std::string nameFile)
{
    std::cout << nameFile << std::endl;
}

/* Общий метод добавления */
bool Airfoil::addCoeff(std::map<float,float> &map, float alfa, float coeff){
    return map.insert(std::pair<float, float>(alfa, coeff)).second;
}

void Airfoil::addCl(float alfa, float cl)
{
    if(!addCoeff(cl_, alfa, cl)) std::cerr << "Значение уже определено" << std::endl;
}

void Airfoil::addCd(float alfa, float cd)
{
    addCoeff(cl_, alfa, cd);
}

void Airfoil::addCm(float alfa, float cm)
{
    addCoeff(cl_, alfa, cm);
}

void Airfoil::print()
{
    for (std::map<float,float>::iterator i = cl_.begin(); i != cl_.end(); ++i){
        std::cout << i->first << " " << i->second << std::endl;
    }
}
