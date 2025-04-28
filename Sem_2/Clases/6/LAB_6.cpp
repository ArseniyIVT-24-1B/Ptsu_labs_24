#include<iostream>
#include"vector.h"

int main()
{   
    setlocale(LC_ALL, "RU");
    Vector vector(5);
    std::cout << vector << std::endl;


    std::cout << "Введите значения элементов: ";
    std::cin >> vector;
    std::cout << vector << std::endl;


    vector[2] = 100;
    std::cout << "Третий элемент изменён: " << vector << std::endl;

    std::cout << "Размер вектора: " << vector() << std::endl;


    Vector vector2 = vector + 10;
    std::cout << "v2 = v1 + 10: " << vector2 << std::endl;




    Iterator it = vector.first();
    Iterator end = vector.last();


    std::cout << "Первый элемент: " << *it << std::endl;


    ++it;
    std::cout << "Второй элемент: " << *it << std::endl;


    for (Iterator i = vector.first(); i != vector.last(); ++i) {
        std::cout << *i << " ";
    }
    std::cout << std::endl;
	return 0;
}