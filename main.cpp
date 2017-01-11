#include "airfoil.h"
#include "air.h"
#include <iostream>

int main()
{
    //Air air = Air(273.15-60);
    AirfoilData s822;
    for(double i = -3; i < 10; i++)
    std::cout << i << " " << s822.getCl(i) << std::endl;

    return 0;
}

