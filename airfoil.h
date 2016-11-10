#ifndef AIRFOIL_H
#define AIRFOIL_H

#include <iostream>
#include <string>
#include <map>
#include <vector>


/** Этот класс описывает всё что есть по аэродинамическому профилю
 * для различных чисел Рейнольдса и Маха.
 * */
class Airfoil
{
public:

    Airfoil();
    Airfoil(std::string);
    ~Airfoil();

    void addCl(float, float);
    void addCd(float, float);
    void addCm(float, float);

private:
    float thickness_; //Максимальная толщина профиля
    
    /** Внутренний класс для отделения характеристики по числам */
    class AirfoilData
    {
    public:
        AirfoilData();
        AirfoilData(float);

        void addPoint(float, float, float, float);
    private:
        int reynolds_; //число Рейнольдса
        int mach_; //число Маха
        std::vector <float> alpha_;
        std::vector <float> cl_;
        std::vector <float> cd_;
        std::vector <float> cm_;
    };

    /* Для каждого Re */
    std::vector <AirfoilData> airfoilData;
};

#endif // AIRFOIL_H
