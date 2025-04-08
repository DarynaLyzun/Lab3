#pragma once
#include <functional>

typedef std::function<double(double)> Func;

class Solve_class
{
    protected:
        double eps;
    public:
        Solve_class();
        ~Solve_class();

        void setTolerance(double vol_eps);
};