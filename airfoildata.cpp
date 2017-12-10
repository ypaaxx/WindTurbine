#include "airfoildata.h"
#include "algorithm"

/** Cодержащий точки характеристики профиля
 * по фиксированным числам Рейнольдса и Маха */
AirfoilData::AirfoilData()
{
    // Инициация векторов продувки

    cl_ = new std::vector<Point*> ;

    cd_ = new std::vector<Point*> ;

    cm_ = new std::vector<Point*> ;


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
    double a;
    a << bufer;
    */
}

/** Добавления новой точки данных*/
void AirfoilData::addPoint(double alpha, double cl, double cd, double cm)
{
    addCl(alpha, cl);
    addCd(alpha, cd);
    addCm(alpha, cm);

    initiatedMinMax = false;
}

void AirfoilData::addPoint(double alpha, double cl, double cd)
{
    addCl(alpha, cl);
    addCd(alpha, cd);

    initiatedMinMax = false;
}

void AirfoilData::addCl(double alpha, double cl)
{
    cl_->push_back(new Point(alpha, cl));
    std::sort(cl_->begin(), cl_->end(), Point::comparationX);

    initiatedMinMax = false;
}

void AirfoilData::addCd(double alpha, double cd)
{
    cd_->push_back(new Point(alpha, cd));
    std::sort(cd_->begin(), cd_->end(), Point::comparationX);

    initiatedMinMax = false;
}

void AirfoilData::addCm(double alpha, double cm)
{
    cm_->push_back(new Point(alpha, cm));
    std::sort(cm_->begin(), cm_->end(), Point::comparationX);

    initiatedMinMax = false;
}

double AirfoilData::getSome(std::vector<Point *> *some, const double alpha)
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
double AirfoilData::getCl(const double alpha)
{
    return getSome(cl_, alpha);
}

double AirfoilData::getCd(const double alpha)
{
    return getSome(cd_, alpha);
}

double AirfoilData::getCm(const double alpha)
{
    return getSome(cm_, alpha);
}

double AirfoilData::getMu(double alpha){return getCl(alpha)/getCd(alpha);}

void AirfoilData::inintiateMinMax(){
    maxAlpha = cl_->front()->x();
    if(cd_->front()->x() < maxAlpha) maxAlpha = cd_->front()->x();
    minAlpha = cl_->back()->x();
    if(cd_->back()->x() > minAlpha) minAlpha = cd_->back()->x();

    //Это почему то не работает. Нельзя ссылаться на функцию-член
    //maxFunction( &AirfoilData::getMu, minAlpha, maxAlpha);

    //Метод золотого сечения

    double delta = 0.0005; //точность до третьего знака
    double f = 0.5 + sqrt(5)/2;

    double a=maxAlpha;
    double b=minAlpha;

    Point A(a);
    Point B(b);

    double x1 = b-(b-a)/f;
    double x2 = a+(b-a)/f;
    Point p1( x1, getMu( x1 ) );
    Point p2( x2, getMu( x2 ) );

    do{
        if ( Point::comparationY(&p1, &p2)){
            A = p1;
            p1 = p2;
            p2.setX(A.x()+(B.x()-A.x())/f);
            p2.setY(getMu(p2.x()));

        } else {
            B = p2;
            p2 = p1;
            p1.setX(B.x()-(B.x()-A.x())/f);
            p1.setY(getMu(p1.x()));
        }

    }while( fabs(B.x() - A.x()) > delta);

    maxMuAlpha = (A.x() + B.x())/2;

    initiatedMinMax = true;

}

