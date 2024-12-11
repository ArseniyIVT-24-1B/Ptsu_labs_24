#include <iostream>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");

    int n, num;
    bool plus = false;
    bool minus = false;

    cout << "введните количество чисел в последовательности:  " << endl;
    cin >> n;
    cout << "введите последовательность:  " << endl;
    for (int i = 0; i < n; i++) {
        cin >> num;
        if (!plus && !minus) {
            if (num > 0) {
                plus = true;
            }
            else if (num < 0) {
                minus = true;
            }
        }
    }
    if (plus) { cout << "сначала ввели положительное число"; }
    else if(minus) { cout << "сначала ввели отрицательное число"; }
    else { cout << "ввели только нули("; }
}