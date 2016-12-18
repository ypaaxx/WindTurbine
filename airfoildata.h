#ifndef AIRFOILDATA_H
#define AIRFOILDATA_H

#include <vector>
#include <libalglib/interpolation.h>

class AirfoilData
{
public:
    AirfoilData();
    AirfoilData(float);
    AirfoilData(float, float);

    void setReynolds(int const reynolds) { reynolds_ = reynolds;}
    void setMach(float const mach) { mach_ = mach;}

    void addPoint(float, float, float, float);

    void makeInterpolant();

    float getCl(float);
    float getCd(float);
    float getCm(float);

    float getReynolds() const { return reynolds_; }
    float getMach() const { return mach_; }

private:
    int reynolds_; //число Рейнольдса
    float mach_; //число Маха

    std::vector<double> alpha_;
    std::vector<double> cl_;
    std::vector<double> cd_;
    std::vector<double> cm_;

    alglib::real_1d_array alg_alpha_, alg_cl_, alg_cd_, alg_cm_;
    alglib::spline1dinterpolant sl_, sd_, sm_;


    /* по всей видимости не удачная затея, ведь врятли мы найдем такой эксперемент,
     * что данные это значения коэфффициентов при разных углах атаки
    std::map <float, float> cl_;
    std::map <float, float> cd_;
    std::map <float, float> cm_;
    */
};

#endif // AIRFOILDATA_H
