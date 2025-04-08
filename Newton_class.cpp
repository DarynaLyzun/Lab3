#include "Newton_class.h"

Newton_class::Newton_class(){};
Newton_class::~Newton_class(){};

double Newton_class::derivative(Func f, double x)
{
    return (f(x + eps) - f(x - eps)) / (2 * eps);
}

int Newton_class::count(Func f, double &x)
{
    double x1;
    do
    {
        x1 = x;
        x = x1 - (f(x1) / derivative(f, x1));
    } while (fabs(x - x1) >= eps);

    return 0;
}