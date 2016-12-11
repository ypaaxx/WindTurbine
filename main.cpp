#include "airfoil.h"
#include "air.h"
#include <iostream>

int main()
{
    Air air = Air(273.15-60);
    Airfoil expero = Airfoil();
    std::cout << expero.getName() << std::endl;


    //Airfoil airfoil = Airfoil("/home/fura/www/index.html");
    std::cout << air.getTemperature() << std::endl;
    std::cout << air.getDensity() << std::endl;
    std::cout << air.getViscosity() << std::endl;
    return 0;
}

