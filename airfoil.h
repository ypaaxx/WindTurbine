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
    void setThickness(double thickness) { thickness_ = thickness;}
    void setDefaultReynolds (int reynolds) { defaultReynolds_ = reynolds;}
    void setDefaultData (AirfoilData &defaultData) { defaultData_ = &defaultData;}

    void addPoint(double reynolds, double mach, double alpha, double cl, double cd, double cm);
    void addPoint(double alpha, double cl, double cd);

    double getCl(double Re, double M, double alpha) const;
    double getCl(double alpha, double Re) const;
    double getCl(double alpha) const;

    double getCd(double Re, double M, double alpha) const;
    double getCd(double alpha, double Re) const;
    double getCd(double alpha) const;

    AirfoilData *data(double Re = 0);

    double getSome(double alpha) const;
private:
    char name_[30]; // Название профиля
    double thickness_; // Максимальная толщина профиля
    static double defaultReynolds_;
    AirfoilData* defaultData_;

    /* Для каждого Re */
    std::vector <int> numerReynolds_;
    std::vector <AirfoilData*> airfoilDataRe_;

    /* Для каждого М, ссылки на то что в по Re*/
    std::vector <double> numerMach_;
    std::vector <AirfoilData*> airfoilDataM_;
};

#endif // AIRFOIL_H
