#include "airfoil.h"
#include "fluid.h"

int main()
{
    Fluid air = Fluid();

    Airfoil airfoil = Airfoil("/home/fura/www/index.html");
    std::cout << "exit" << std::endl;
    return 0;
}

