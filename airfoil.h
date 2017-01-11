#ifndef AIRFOIL_H
#define AIRFOIL_H

#include <string>
#include <vector>
#include <airfoildata.h>
#include <mysql_connection.h>

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
    char getName()  {return *name_;}

    float getSome(float) const;
private:
    char name_[30]; // Название профиля
    float thickness_; // Максимальная толщина профиля 
    int defaultReynolds;

    /* Для каждого Re */
    std::vector <AirfoilData> airfoilDataRe;

    /* Для каждого М, ссылки на то что в по Re*/
    std::vector <AirfoilData> airfoilDataM;
};

#endif // AIRFOIL_H
