#include <iostream>
#include <cmath>
using namespace std;
int main()
{   
    setlocale(LC_ALL, "Russian");
    
    float a, b, c;
    float fa, fb, fc;
    double eps = 0.000001;

    a = 1;
    b = 2;

    while (b - a > eps) {

        c = (a + b) / 2;
        fa = pow(a, 3) - a - 1;
        fb = pow(b, 3) - b - 1;
        fc = pow(c, 3) - c - 1;

        if (fa * fc < 0) { b = c; }
        else if (fc * fb < 0) { a = c; }
        else { cout << "Что-то не так"; }

    }

    cout << a << endl << b;


    return 0;
}