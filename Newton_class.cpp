#include "Newton_class.h"
#include <iostream>
using namespace std;

Newton_class::Newton_class(){};
Newton_class::~Newton_class(){};

void Newton_class::setMax(int vol_max)
{
    max = vol_max;
}

double Newton_class::derivative(Func f, double x)
{
    return (f(x + eps) - f(x - eps)) / (2 * eps);
}

int Newton_class::count(Func f, double &x)
{
    if (isnan(f(x)) || isnan(derivative(f, x)) || derivative(f, x) == 0)
        return 1;
    else
    {
        double x1;
        int i = 0;
        do
        {
            x1 = x;
            x = x1 - (f(x1) / derivative(f, x1));
            i++;

            if (isnan(f(x)) || isnan(derivative(f, x)) || derivative(f, x) == 0)
                return 2;
        } while (fabs(x - x1) >= eps && i < max);

        if (i == max)
            return 3;
        else
            return 0;
    }
}