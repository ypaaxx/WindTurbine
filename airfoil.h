#ifndef AIRFOIL_H
#define AIRFOIL_H

#include <iostream>
#include <string>
#include <map>

class Airfoil
{
public:
    Airfoil();
    Airfoil(std::string);

    void addCl(float, float);
    void addCd(float, float);
    void addCm(float, float);

    void print();

private:
    std::map <float, float> cl_;
    std::map <float, float> cd_;
    std::map <float, float> cm_;

    bool addCoeff (std::map<float,float> &, float, float);

};

#endif // AIRFOIL_H
