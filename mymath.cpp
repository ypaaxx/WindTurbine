#include "mymath.h"

/**
 * То что я сам напихал, всякие интерполяции
*/

double Point::lineInterpolation( const Point *one, const Point *two, const double x)
{
    return ( one->y() + (two->y() - one->y()) / (two->x() - one->x()) * (x - one->x()) );
}

bool Point::comparationY(const Point *lower, const Point *greater)
{
    return greater->y() > lower->y();
}

bool Point::comparationX(const Point *lower, const Point *greater)
{
    return greater->x() > lower->x();
}

double maxFunction(double (*function)(double), double a, double b)
{
    //Метод золотого сечения

    double  delta = 0.0005; //точность
    double f = 0.5 + sqrt(5)/2;

    Point A(a);
    Point B(b);

    double x1 = b-(b-a)/f;
    double x2 = a+(b-a)/f;
    Point p1( x1, function( x1 ) );
    Point p2( x2, function( x2 ) );

    do{
        if ( Point::comparationY(&p1, &p2)){
            A = p1;
            p1 = p2;
            p2.setX(A.x()+(B.x()-A.x())/f);
            p2.setY(function(p2.x()));

        } else {
            B = p2;
            p2 = p1;
            p1.setX(B.x()-(B.x()-A.x())/f);
            p1.setY(function(p1.x()));
        }

    }while( fabs(B.x() - A.x()) > delta);

    return (A.x() + B.x())/2;
}

