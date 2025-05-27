#pragma once
#include <iostream>
using namespace std;

class Time {
private:
    int min, sec;
public:
    Time(); // Конструктор по умолчанию
    Time(int m, int s); // Конструктор с параметрами
    Time(const Time& t); // Конструктор копирования

    int get_min() const { return min; }
    int get_sec() const { return sec; }

    Time operator+(const Time& other) const;
    Time operator/(int divisor) const;
    bool operator<(const Time& other) const;
    bool operator>(const Time& other) const;

    friend ostream& operator<<(ostream& os, const Time& t);
    friend istream& operator>>(istream& is, Time& t);
};