#include "airfoildata.h"
#include "algorithm"

/** Cодержащий точки характеристики профиля
 * по фиксированным числам Рейнольдса и Маха */
AirfoilData::AirfoilData()
{
    /*
    // S822
    reynolds_ = 600000;
    mach_ = 0;
    addPoint(-3, -0.04, 0.0076, -0.0746);
    addPoint(-2, 0.068, 0.0072, -0.0772);
    addPoint(-1, 0.176, 0.0072, -0.0798);
    addPoint(0, 0.284, 0.0073, -0.0823);
    addPoint(1, 0.391, 0.0075, -0.0845);
    addPoint(2, 0.497, 0.0077, -0.0866);
    addPoint(3, 0.602, 0.0080, -0.0885);
    addPoint(4, 0.707, 0.0083, -0.0903);
    addPoint(5, 0.811, 0.0087, -0.0917);
    addPoint(6, 0.911, 0.0092, -0.0924);
    addPoint(7, 0.964, 0.0167, -0.0836);
    addPoint(8, 1.044, 0.0189, -0.0809);
    makeInterpolant();
    inintiateMinMax();
    */


}
AirfoilData::AirfoilData(std::string file)
{

}

/** Добавления новой точки данных*/
void AirfoilData::addPoint(float alpha, float cl, float cd, float cm)
{
    alpha_.push_back(alpha);
    cl_.push_back(cl);
    cd_.push_back(cd);
    cm_.push_back(cm);
}

void AirfoilData::addPoint(float alpha, float cl, float cd)
{
    addPoint(alpha, cl, cd, 0.3);
}

/** Вычисление коэффициентов интерполяции */
void AirfoilData::makeInterpolant()
{
    alg_alpha_.setcontent(alpha_.size(), &alpha_[0]);
    alg_cl_.setcontent(cl_.size(), &cl_[0]);
    alg_cd_.setcontent(cd_.size(), &cd_[0]);
    alg_cm_.setcontent(cm_.size(), &cm_[0]);

    alglib::spline1dbuildcubic(alg_alpha_, alg_cl_, sl_);
    alglib::spline1dbuildcubic(alg_alpha_, alg_cd_, sd_);
    alglib::spline1dbuildcubic(alg_alpha_, alg_cm_, sm_);
}

void AirfoilData::inintiateMinMax()
{
    /*
    minAlpha = std::min_element(alpha_[0], alpha_.);
    maxAlpha = std::max_element(alpha_.begin(), alpha_.end());
    */
}

/** Получение коэффициента подьемной силы Cl по углу атаки */
float AirfoilData::getCl(const float alpha)
{
    return alglib::spline1dcalc(sl_, alpha);
}

float AirfoilData::getCd(const float alpha)
{
    return alglib::spline1dcalc(sd_, alpha);
}

float AirfoilData::getCm(const float alpha)
{
    return alglib::spline1dcalc(sm_, alpha);
}

