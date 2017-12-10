#include "airfoil.h"
#include "air.h"
#include "rotor.h"

#include <iostream>

int main()
{
    Air air = Air(-30);

    Airfoil espero01;
    espero01.setThickness(0.1);
    Airfoil espero02;
    espero02.setThickness(0.2);

    double alpha[] = {-5, -2.5, 0, 2.5, 5, 7.5, 10, 12.5, 15, 17.5};
    double cy_01[] = {0, 17, 35, 55, 73, 85.5, 89.5, 95*10/12, 88*10/12, 84*10/12};
    double u_01[] = {0.1, 0.085, 0.034, 0.016, 0.015, 0.03, 0.1, 0.18, 0.3, 0.4};
    double cy_02[] = {36, 56, 75, 90, 102, 105, 110, 129*10/12, 126*10/12, 122*10/12};
    double u_02[] = {0.03, 0.018, 0.01, 0.01, 0.02, 0.03, 0.06, 0.1, 0.13, 0.16};

    for(int i = 0; i < 10; i++){
        espero01.addPoint(alpha[i], cy_01[i]*0.012, u_01[i]*cy_01[i]*0.012);
        espero02.addPoint(alpha[i], cy_02[i]*0.012, u_02[i]*cy_02[i]*0.012);
    }

    Condition cond(&air, 10, 800);
    Rotor rotor(2, 0.5, 0.2) ;

    Section sec(&rotor, &espero01, 5.0, 0.8);
    SectionData *data = sec.glouert(cond);

    return 0;
}


