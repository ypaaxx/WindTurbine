#ifndef SECTION_H
#define SECTION_H

#include "airfoil.h"
#include "air.h"
#define _USE_MATH_DEFINES
#include "math.h"
#include "sectiondata.h"
#include "rotor.h"

/**
 * Элемент лопасти
 */

class Section
{
public:
    Section(Rotor* rotor, float r, float tetta, float b, Airfoil *airfoil);
    SectionData *glouert(const Air &air, float wind, float rpm);

private:
    int numerBlades_; // Число лопастей
    Airfoil *airfoil_; // Профиль
    float tetta_; // (rad) Угол установки
    float r_; // Радиус относительный
    float b_; // Хорда относительная

    Rotor *rotor_;

};

#endif // SECTION_H
