#ifndef AIRFOIL_H
#define AIRFOIL_H

#include <string>
#include <vector>
#include <airfoildata.h>
//#include <mysql_connection.h>

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
    //char getName()  {return *name_;}
    void setThickness(float thickness) { thickness_ = thickness;}
    void setDefaultReynolds (int reynolds) { defaultReynolds_ = reynolds;}
    void setDefaultData (AirfoilData &defaultData) { defaultData_ = &defaultData;}

    void addPoint(float reynolds, float mach, float alpha, float cl, float cd, float cm);
    void addPoint(float alpha, float cl, float cd);

    float getCl(float, float, float) const;
    float getCl(float, float) const;
    float getCl(float) const;

    float getSome(float) const;
private:
    char name_[30]; // Название профиля
    float thickness_; // Максимальная толщина профиля 
    int defaultReynolds_;
    AirfoilData* defaultData_;

    /* Для каждого Re */
    std::vector <int> numerReynolds_;
    std::vector <AirfoilData*> airfoilDataRe_;

    /* Для каждого М, ссылки на то что в по Re*/
    std::vector <double> numerMach_;
    std::vector <AirfoilData*> airfoilDataM_;
};

#endif // AIRFOIL_H
