#ifndef MYMATH_H
#define MYMATH_H

//using namespace mymath;

class Point
{
private:
    double x_;
    double y_;

public:

    Point (double x = 0, double y = 0){
        setX(x);
        setY(y);
    }

    void inline setX(double x){ x_ = x; }
    void inline setY(double y){ y_ = y; }

    double inline x() const { return x_; }
    double inline y() const { return y_; }

    // Возращает У по линейной апроксимации между двумя точками
    static double lineInterpolation(const Point *one, const Point *two, const double x);
    // Сравнивают У или Х двух точек, если у первой больше - да
    static bool comparationY(const Point *lower, const Point *greater);
    static bool comparationX(const Point *lower, const Point *greater);
};



#endif // MYMATH_H
