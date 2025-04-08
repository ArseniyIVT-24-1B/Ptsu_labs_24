#include <iostream>
using namespace std;

//Написать перегруженные функции и основную программу, которая их вызывает. 
//а) для сложения целых чисел; 
//б) для сложения комплексных чисел.


int add(int a, int b) {
    return a + b;
}
void add(int a1, int a2, int b1, int b2, int &z1, int &z2) {
    z1 = a1 + a2;
    z2 = b1 + b2;
}


int main() 
{   
    int a, b;
    int a1, b1, a2, b2, z1, z2;  
    setlocale(LC_ALL, "ru");
    cout << "Ведите натуральные числа, которые надо сложить: ";
    cin >> a;
    cin >> b;
    cout << "Сумма эти чисел: " << add(a, b) << endl;

    cout << "Введите дейстиветельную и мнимую часть первого слагаемого: ";
    cin >> a1;
    cin >> b1;

    cout << "Введите дейстиветельную и мнимую часть второго слагаемого: ";
    cin >> a2;
    cin >> b2;
    add(a1, a2, b1, b2, z1, z2);

    cout << "Сумма равна: " << z1 << " + " << z2 << "i";

    return 0;
}
