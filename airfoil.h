#ifndef AIRFOIL_H
#define AIRFOIL_H

#include <iostream>
#include <string>
#include <map>
#include <vector>


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

    void setName(std::string);
    void setThickness(float);
    void addPoint(float, float, float, float, float, float);
    float getCl(float,float,float);
    float getCl(float,float);
    float getCl(float);

private:
    std::string name_; // Название профиля
    float thickness_; // Максимальная толщина профиля

    
    /** Внутренний класс для отделения характеристики по числам подобия
     * Числа постоянны для характеристики */
    class AirfoilData
    {
    public:
        AirfoilData();
        AirfoilData(float);
        AirfoilData(float, float);

        void setReynolds(int);
        void setMach(float);
        void addPoint(float, float, float, float);
        float getCl(float);
        float getCd(float);
        float getCm(float);

    private:
        int reynolds_; //число Рейнольдса
        int mach_; //число Маха
        std::map <float, float> cl_;
        std::map <float, float> cd_;
        std::map <float, float> cm_;
    };

    /* Для каждого Re */
    std::map <int, AirfoilData> airfoilDataRe;

    /* Для каждого М, ссылки на то что в по Re*/
    std::map <int, AirfoilData&> airfoilDataM;
};

#endif // AIRFOIL_H
