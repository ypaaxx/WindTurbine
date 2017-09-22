#include "mymath.h"

/* То что я сам напихал, всякие интерполяции */

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
