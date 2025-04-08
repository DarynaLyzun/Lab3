#pragma once
#include "Solve_class.h"
#include <cmath>

class Newton_class : public Solve_class
{
    public:
        Newton_class();
        ~Newton_class();

        double derivative(Func f, double x);

        int count(Func f, double &x);
};