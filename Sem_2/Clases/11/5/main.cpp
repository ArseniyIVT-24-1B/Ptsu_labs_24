#include "Vector.h"
#include <iostream>

int main() {
    setlocale(LC_ALL, "Ru");
    Vector<int> vec;


    std::cout << "������� �������� ���������: ";
    for (int i = 0; i < 5; ++i) {
        int num;
        std::cin >> num;
        vec.push(num);
    }

    std::cout << "������: ";
    vec.print();


    vec.addAverageToElements();


    std::cout << "������ ����� ���������� �������� ���������������: ";
    vec.print();

    return 0;
}