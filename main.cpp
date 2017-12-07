#include "airfoil.h"
#include "air.h"
#include "rotor.h"
#include "section.h"

#include <iostream>

int main()
{
    Air air = Air(273.15-60);

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

    Rotor rotor(2, 0.5, 0.1) ;
    std::vector <SectionData*> data;
    for(float r_=0.2; r_ < 1; r_+=0.1)
    {
        Section *section = new Section(&rotor, r_, 50-r_*47,0.070-r_*40, &espero02);
        rotor.addSection(section);
        data.push_back(section->glouert(air, 10, 600));
        std::cout << data.back()->get_dM() << std::endl;
    }


    return 0;
}

