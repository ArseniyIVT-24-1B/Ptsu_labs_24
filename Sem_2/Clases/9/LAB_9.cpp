#include "Vector.h"
#include <iostream>
using namespace std;

int main() {

    setlocale(LC_ALL, "Ru");

    try {

        Vector vector(5);
        cout << "������: " << vector;


        for (int i = 0; i < 5; i++) {
            vector[i] = i * 2;
        }
        cout << "���������� �������: " << vector;


        Vector vector2 = vector + 10;
        cout << "���������� ��������: " << vector2;


        --vector2;
        cout << "�������� ������� ��������: " << vector2;


        //��������� ����������:

        //Vector v3(MAX_SIZE + 1); 

        
        //cout << vector[-1];

        
        //cout << vector[10]; 


        //Vector v4(MAX_SIZE);
        //v4 = v4 + 1;
        

        //Vector v5;
        //--v5;

    }
    catch (error e) {
        e.print();
    }

    return 0;
}