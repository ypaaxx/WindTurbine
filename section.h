#ifndef SECTION_H
#define SECTION_H
#include "airfoil.h"
#include "air.h"
#define _USE_MATH_DEFINES
#include "math.h"
#include "sectiondata.h"

class Section
{
public:
    Section();
    SectionData *glouert(const Air &air, float wind, float rotationSpeed);
private:
    int numerBlades_; // Число лопастей
    Airfoil airfoil_; // Профиль
    float tetta_; // (rad) Угол установки
    float r_; // Радиус относительный
    float b_; // Хорда относительная
};

SectionData *glouert(const Section &section, const Air &air, float wind, float rotationSpeed);

#endif // SECTION_H
