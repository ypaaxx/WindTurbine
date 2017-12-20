#include "airfoil.h"
#include "air.h"
#include "rotor.h"

#include <iostream>

int main()
{
    Air air = Air(15);

    Airfoil plateBlade;
    plateBlade.setThickness(0.1);

    // f=0.1
    double alpha[] = {0.00,
                      2.5,
                      5.00,
                      7.5,
                      10.00,
                      12.5,
                      15.00};
    double cd[] = {0.065838164,
                   0.054383829,
                   0.051563479,
                   0.059871872,
                   0.081094593,
                   0.10294809,
                   0.17503061 };
    double cy[] = {0.21561506,
                   0.6533426,
                   0.9934518,
                   1.1747366,
                   1.2657257,
                   1.3340159,
                   1.2694037};


    for(int i = 0; i < 7; i++){
        plateBlade.addPoint(alpha[i], cy[i], cd[i]);
    }

    Condition cond(&air, 10, 800);
    Rotor rotor(2, 0.5, 0.17);

    Section sec(&rotor, &plateBlade, 4.189, 0.6);

    Section sec2(&rotor, 0.6, 11.2, 0.0495, &plateBlade);
    //sec.setChord(0.042);
    //sec.setTetta(6*M_PI/180);

    SectionData *data = sec2.glouert(cond);
    std::cout << data->a() << std::endl;

    return 0;
}


