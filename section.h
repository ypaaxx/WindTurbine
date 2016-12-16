#ifndef SECTION_H
#define SECTION_H
#include "airfoil.h"
#include "air.h"
#include "sectiondata.h"

class Section
{
public:
    Section();
private:
    int numerBlades_; // Число лопастей
    Airfoil airfoil_; // Профиль
    float alpha_; // (rad) Угол установки
    float r_; // (mm) Радиус
    float b_; // (mm) Хорда
};

float glouert(const Section& section, const Air& air, SectionData& target);

#endif // SECTION_H
