#ifndef ROTOR_H
#define ROTOR_H

#include <vector>

/**
 * Обьединяет несколько элементарых лопастей в вектор
 */

class Section;

class Rotor
{
public:
    Rotor(int numberOfBlades, float R_tip, float R_hub);

    void addSection(Section* newSection){
        blade->push_back(newSection);
    }
    int getNumerBlades() {return numberBlades;}

    float getR_tip() const{return rTip;}

private:
    int numberBlades;
    float rTip;
    float rHub;

    std::vector <Section*> *blade;
};


#endif // ROTOR_H
