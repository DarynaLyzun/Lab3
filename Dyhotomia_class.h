#pragma once
#include "Solve_class.h"
#include <cmath>

class Dyhotomia_class : public Solve_class
{
    private:
        double a;
        double b;
    public:
        Dyhotomia_class();
        ~Dyhotomia_class();

        void setVolumes(double vol_a, double vol_b);

        int count(Func f, double &x);
};