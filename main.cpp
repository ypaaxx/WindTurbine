#include "airfoil.h"

int main()
{
    Airfoil airfoil = Airfoil("fuck off");
    airfoil.addCl(0.5, 0.5);
    airfoil.addCl(0.4, 0.5);
    airfoil.addCl(0.4, 0.6);
    airfoil.addCl(0.4, 0.7);
    airfoil.print();
    return 0;
}

