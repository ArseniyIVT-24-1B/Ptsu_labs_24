#include "Vector.h"
#include <iostream>

int main() {
    setlocale(LC_ALL, "Ru");
    Vector<int> vec;


    std::cout << "Введите значения элементов: ";
    for (int i = 0; i < 5; ++i) {
        int num;
        std::cin >> num;
        vec.push(num);
    }

    std::cout << "Вектор: ";
    vec.print();


    vec.addAverageToElements();


    std::cout << "Вектор после добавления среднего арифметического: ";
    vec.print();

    return 0;
}