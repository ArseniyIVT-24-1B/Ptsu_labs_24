#include "vector.h"
#include "time.h"
#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "Ru");

    cout << "=== ������ � �������� ===" << endl;
    Vector<int> intVec(3, 0);
    cout << "������� ��������: ";
    cin >> intVec;
    cout << "��� ������: " << intVec << endl;
    cout << "������: " << intVec() << endl;

    Vector<int> intVecPlus = intVec + 5;
    cout << "��� ������ + 5: " << intVecPlus << endl << endl;


    cout << "=== ������ � �������� ===" << endl;
    Time t(2, 30);
    cout << "�����: " << t << endl;

    Time tPlus = t + 45;
    cout << "����� + 45 ������: " << tPlus << endl << endl;


    cout << "=== ������ � �������� � �������� ===" << endl;
    Vector<Time> timeVec(2, Time(0, 0));
    cout << "������� ������ � �������(2 ����):" << endl;
    cin >> timeVec;
    cout << "������: " << timeVec << endl;


    Time thirtySec(0, 30);
    Vector<Time> timeVecPlus = timeVec + thirtySec;
    cout << "��� ������ + 30 ������: " << timeVecPlus << endl;

    return 0;
}