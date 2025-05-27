#include "Time.h"

Time::Time() : min(0), sec(0) {} // Конструктор по умолчанию

Time::Time(int m, int s) : min(m), sec(s) {} // Конструктор с параметрами

Time::Time(const Time& t) : min(t.min), sec(t.sec) {} // Конструктор копирования

Time Time::operator+(const Time& other) const {
    int total_sec = (min * 60 + sec) + (other.min * 60 + other.sec);
    return Time(total_sec / 60, total_sec % 60);
}

Time Time::operator/(int divisor) const {
    if (divisor == 0) {
        throw invalid_argument("Division by zero");
    }
    int total_sec = min * 60 + sec;
    total_sec /= divisor;
    return Time(total_sec / 60, total_sec % 60);
}

bool Time::operator<(const Time& other) const {
    return (min * 60 + sec) < (other.min * 60 + other.sec);
}

bool Time::operator>(const Time& other) const {
    return (min * 60 + sec) > (other.min * 60 + other.sec);
}

ostream& operator<<(ostream& os, const Time& t) {
    os << t.min << ":" << (t.sec < 10 ? "0" : "") << t.sec;
    return os;
}

istream& operator>>(istream& is, Time& t) {
    char colon;
    is >> t.min >> colon >> t.sec;
    if (colon != ':' || t.sec >= 60) {
        is.setstate(ios::failbit);
    }
    return is;
}