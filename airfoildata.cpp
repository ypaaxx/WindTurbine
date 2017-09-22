#include "airfoildata.h"
#include "algorithm"

/** Cодержащий точки характеристики профиля
 * по фиксированным числам Рейнольдса и Маха */
AirfoilData::AirfoilData()
{
    // Инициация векторов продувки
    cl_ = new std::vector<Point*>;
    cd_ = new std::vector<Point*>;
    cm_ = new std::vector<Point*>;

}
AirfoilData::AirfoilData(std::string fileName)
{
    std::ifstream input;
    input.open(fileName);

    std::string bufer;
/*  //Кю!
    //Игнорирование первых 12 строк
    for (int i = 0; i < 12; i++)
        input.getline(bufer, 100);

    input.getline(bufer, 100);
    float a;
    a << bufer;
    */
}

/** Добавления новой точки данных*/
void AirfoilData::addPoint(float alpha, float cl, float cd, float cm)
{
    addCl(alpha, cl);
    addCd(alpha, cd);
    addCm(alpha, cm);
}

void AirfoilData::addPoint(float alpha, float cl, float cd)
{
    addCl(alpha, cl);
    addCd(alpha, cd);
}

void AirfoilData::addCl(float alpha, float cl)
{
    cl_->push_back(new Point(alpha, cl));
    std::sort(cl_->begin(), cl_->end(), Point::comparationX);
}

void AirfoilData::addCd(float alpha, float cd)
{
    cd_->push_back(new Point(alpha, cd));
    std::sort(cd_->begin(), cd_->end(), Point::comparationX);
}

void AirfoilData::addCm(float alpha, float cm)
{
    cm_->push_back(new Point(alpha, cm));
    std::sort(cm_->begin(), cm_->end(), Point::comparationX);
}

double AirfoilData::getSome(std::vector<Point *> *some, const double alpha) const
{
    for (auto i = some->cbegin(); i != some->cend(); ++i){
        Point *point = *i;
        // При точном совпадении - возращение точного числа
        if(point->x() == alpha)
            return point->y();
        // Если достигнут конец списка - выбрасываем 0
        if(point == some->back())
            throw 0;
        // В найденом промежутке интерполируем
        if (point->x() < alpha )
            return Point::lineInterpolation(point, *(i+1), alpha);
    }
    return 0;
}

/** Получение коэффициента подьемной силы Cl по углу атаки */
float AirfoilData::getCl(const float alpha)
{
    double cl=0;
    try{
        cl = getSome(cl_, alpha);
    } catch(int ex) {
        std::cout << "Мать их! " << cl << " " << alpha << std::endl;
    }

    return cl;
}

float AirfoilData::getCd(const float alpha)
{
    return getSome(cd_, alpha);
}

float AirfoilData::getCm(const float alpha)
{
    return getSome(cm_, alpha);
}

