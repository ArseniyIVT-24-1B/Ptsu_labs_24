#pragma once

#include <iostream>
#include <iomanip>

class Money {
private:
    long rubles;
    int kopecks;

    void normalize();

public:
    Money(long r = 0, int k = 0);

    bool operator<(const Money& other) const;
    bool operator==(const Money& other) const;
    Money operator+(const Money& other) const;
    Money operator/(int divisor) const;

    friend std::ostream& operator<<(std::ostream& os, const Money& money);
    friend std::istream& operator>>(std::istream& is, Money& money);
};