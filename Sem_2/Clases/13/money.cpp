#include "money.h"

void Money::normalize() {
    rubles += kopecks / 100;
    kopecks %= 100;
    if (kopecks < 0) {
        rubles--;
        kopecks += 100;
    }
}

Money::Money(long r, int k) : rubles(r), kopecks(k) {
    normalize();
}

bool Money::operator<(const Money& other) const {
    return (rubles < other.rubles) ||
        (rubles == other.rubles && kopecks < other.kopecks);
}

bool Money::operator>(const Money& other) const {
    return other < *this;
}

bool Money::operator==(const Money& other) const {
    return rubles == other.rubles && kopecks == other.kopecks;
}

Money Money::operator+(const Money& other) const {
    return Money(rubles + other.rubles, kopecks + other.kopecks);
}

Money Money::operator/(int divisor) const {
    long total = rubles * 100 + kopecks;
    total /= divisor;
    return Money(total / 100, total % 100);
}

std::ostream& operator<<(std::ostream& os, const Money& money) {
    os << money.rubles << "," << std::setw(2) << std::setfill('0') << money.kopecks;
    return os;
}

std::istream& operator>>(std::istream& is, Money& money) {
    char comma;
    is >> money.rubles >> comma >> money.kopecks;
    money.normalize();
    return is;
}