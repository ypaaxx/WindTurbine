#ifndef AIRFOIL_H
#define AIRFOIL_H

#include <string>
#include <map>
#include <airfoildata.h>

/**
 * Этот класс описывает всё что есть по аэродинамическому профилю
 * для различных чисел Рейнольдса и Маха.
*/
class Airfoil
{
public:
    Airfoil();
    Airfoil(const char* file);
    ~Airfoil();

    //void setName(char *name) { name_ = name;}
    void setThickness(float thickness) { thickness_ = thickness;}
    void addPoint(float, float, float, float, float, float);

    float getCl(float, float, float) const;
    float getCl(float, float) const;
    float getCl(float) const;
    char* getName() const {return name_;}

    float getSome(float) const;
private:
    char* name_; // Название профиля
    float thickness_; // Максимальная толщина профиля 

    /* Для каждого Re */
    std::map <int, AirfoilData> airfoilDataRe;

    /* Для каждого М, ссылки на то что в по Re*/
    std::map <int, AirfoilData&> airfoilDataM;
};

#endif // AIRFOIL_H
