#include "Dyhotomia_class.h"

Dyhotomia_class::Dyhotomia_class(){};
Dyhotomia_class::~Dyhotomia_class(){};

void Dyhotomia_class::setVolumes(double vol_a, double vol_b)
{
    a = vol_a;
    b = vol_b;
}

int Dyhotomia_class::count(Func f, double &x)
{
    if(f(a) * f(b) > 0)
        return 1;
    else
    {
        do
        {
            x = (a + b) / 2;

            if(f(a) * f(x) < 0)
                b = x;
            else
                a = x;
        } while (fabs(b - a) >= eps);

        x = (a + b) / 2;

        return 0;
    }
}