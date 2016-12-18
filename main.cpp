#include "airfoil.h"
#include "air.h"
#include <iostream>

int main()
{
    //Air air = Air(273.15-60);
    AirfoilData s822;

    std::cout << s822.getCl(0.5)<< std::endl;
    std::cout << s822.getCd(0.5)<< std::endl;

    return 0;
}

