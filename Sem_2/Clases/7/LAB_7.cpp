#include "vector.h"
#include "time.h"
#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "Ru");

    cout << "=== Работа с вектором ===" << endl;
    Vector<int> intVec(3, 0);
    cout << "Введите значения: ";
    cin >> intVec;
    cout << "Ваш вектор: " << intVec << endl;
    cout << "Размер: " << intVec() << endl;

    Vector<int> intVecPlus = intVec + 5;
    cout << "Ваш вектор + 5: " << intVecPlus << endl << endl;


    cout << "=== Работа с временем ===" << endl;
    Time t(2, 30);
    cout << "Время: " << t << endl;

    Time tPlus = t + 45;
    cout << "Время + 45 секунд: " << tPlus << endl << endl;


    cout << "=== Работа с вектором и временем ===" << endl;
    Vector<Time> timeVec(2, Time(0, 0));
    cout << "Введите минуты и секунды(2 раза):" << endl;
    cin >> timeVec;
    cout << "Вектор: " << timeVec << endl;


    Time thirtySec(0, 30);
    Vector<Time> timeVecPlus = timeVec + thirtySec;
    cout << "Ваш вектор + 30 секунд: " << timeVecPlus << endl;

    return 0;
}