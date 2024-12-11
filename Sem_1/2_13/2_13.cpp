#include <iostream>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");

    float a, b, c;
    float x1, x2;

    cout << "введите коофиценты a, b, c из уравнения вида:" << endl << "a*x^2 + b*x + c = 0" << endl;
    cin >> a;
    cin >> b;
    cin >> c;

    cout << "вы ввели уравнение:    ";
    cout << a << "*x^2 + " << b << "*x + " << c << " = 0" << endl;

    float D = b*b - 4 * a * c;
    if (D < 0) {
        cout << "решений нет";
    }
    else {
        x1 = ((-b + sqrt(D)) / 2*a);
        x2 = ((-b - sqrt(D)) / 2*a);
        
        if (x1 == x2) {
            cout << "уравнение имеет корень: " << endl;
            cout << x1;
        }
        else {
            cout << "уравнение имеет корни:" << endl;
            cout << x1 << endl << x2;
        }
    }
}