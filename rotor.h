#ifndef ROTOR_H
#define ROTOR_H

#include <vector>

#include "airfoil.h"
#include "air.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include "mymath.h"

/**
 * Обьединяет несколько элементарых лопастей в вектор
 */

class Rotor;
class Section;
class SectionData;
class Condition;


/**
 * Параметры среды, ветер, частота
 */
class Condition
{
public:
    Condition(Air *air, double windSpeed, double rpm);

    Air *air() const {return air_;}
    double windSpeed() const {return windSpeed_;}
    double rpm() const {return rpm_;}
private:
    Air *air_;
    double windSpeed_;
    double rpm_;
};

class Rotor
{
public:
    Rotor(int numberOfBlades, double R_tip, double R_hub);

    void addSection(Section* newSection){
        blade->push_back(newSection);
    }
    std::vector<SectionData *> *glouert(const Air *air, double windSpeed, double rpm);
    int getNumerBlades() {return numberBlades;}

    double getR_tip() const{return rTip;}

private:
    int numberBlades;
    double rTip;
    double rHub;

    std::vector <Section*> *blade;
};

Rotor *newRotor(const Condition &condition, int numberOfBlades, double power);

/**
 * Элемент лопасти
 */

class Section
{
public:
    Section(Rotor* rotor, double r, double tetta, double b, Airfoil *airfoil);
    Section(Rotor *rotor, Airfoil *airfoil, double lambda, double r);
    SectionData *glouert(const Air *air, double windSpeed, double rpm);
    SectionData *glouert(const Condition &cond) { return glouert(cond.air(), cond.windSpeed(), cond.rpm());};

    void setChord(double chord_rel){ b_ = chord_rel;}
    void setTetta(double angleRad){ tetta_ = angleRad;}

private:
    Airfoil *airfoil_; // Профиль
    double tetta_; // (rad) Угол установки
    double r_; // Радиус относительный
    double b_; // Хорда относительная

    Rotor *rotor_;

};


/**
 * Результаты решения для элементарной лопасти
 */

class SectionData
{
public:
    SectionData();

    void setA(double a){ a_ = a; }
    void setA2(double a2){ a2_ = a2; }
    void setFi(double fi){ fi_ = fi; }
    void set_dMdr(double dM){ dM_dr= dM; }
    void set_dTdr(double dT){ dT_dr= dT; }
    void setAttack(double attack){ attack_ = attack;}

    double dMdr(){return dM_dr;}
    double a(){return a_;}
    double attack(){return attack_;}

private:

    double a_;  //Коэф. торможения
    double a2_; //Коэф. закрутки
    double fi_; //Угол потока (рад)
    double dM_dr;  //Момент (Н)
    double dT_dr;  //Осевая сила (Н/м)
    double attack_;
    double Re_;

};


#endif // ROTOR_H
