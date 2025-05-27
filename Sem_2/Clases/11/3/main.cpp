#include "Vector.h"
#include <iostream>

int main() {

    setlocale(LC_ALL, "Ru");

        Vector<double> v(5, 1.5);


        v[0] = 2.5;
        v[1] = 3.7;
        v[2] = 1.2;
        v[3] = 4.8;
        v[4] = 0.5;

        cout << "��� ������: " << v << endl;


        double avg = v.average();
        cout << "�������: " << avg << endl;
        v.insert(2, avg);
        cout << "��������� �������: " << v << endl;


        v.remove_max();
        cout << "�������� �������������: " << v << endl;

 
        v.divide_by_min();
        cout << "����� ������� �� �����������: " << v << endl;



    return 0;
}