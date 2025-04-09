#include "Dyhotomia_class.h"
#include "Newton_class.h"
#include <iostream>
using namespace std;

double f6 (double x)
{
    return 3 * x - 4 * log(x) - 5;
}

int main()
{
    Func f{f6};
    Dyhotomia_class* dyh = new Dyhotomia_class;
    dyh->setVolumes(2, 4);
    dyh->setTolerance(0.001);

    double x = 0;
    if(dyh->count(f, x) == 0)
        cout << "Dyhotomia: x = " << x;
    else
        cout << "Немає розв'язку на проміжку";
    

    delete dyh;

    x = 2;

    Newton_class* newt = new Newton_class;
    newt->setTolerance(0.001);
    newt->setMax(100);

    switch (newt->count(f, x))
    {
        case 0:
            cout << "\nNewton: x = " << x;
            break;
        case 1:
            cout << "\nНевдала початкова точка";
            break;
        case 2:
            cout << "\nПомилка в ході обчислення";
            break;
        case 3:
            cout << "\nДосягнено максимальної кількості ітерацій";
            break;
    }

    delete newt;
    
    return 0;
}