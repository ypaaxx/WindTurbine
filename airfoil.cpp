#include "airfoil.h"

Airfoil::Airfoil()
{
    std::cout << "hi, new airfoil" << std::endl;
}

Airfoil::Airfoil(std::string nameFile)
{
    std::cout << nameFile << std::endl;
}

void Airfoil::addCl(float alfa, float cl)
{
    cl_[alfa]=cl;
}

void Airfoil::addCd(float alfa, float cd)
{
    cd_[alfa]=cd;
}

void Airfoil::addCm(float alfa, float cm)
{
    cm_[alfa]=cm;
}

void Airfoil::print()
{
    for (std::map<float,float>::iterator i = cl_.begin(); i != cl_.end(); ++i){
        std::cout << i->first << " " << i->second << std::endl;
    }
}
