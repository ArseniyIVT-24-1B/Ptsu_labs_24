#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Time {
public:
    Time();
    Time(int m, int s);
    Time(const Time& t);
    Time operator=(const Time& t);
    friend ostream& operator<<(ostream& out, const Time& t);
    friend istream& operator>>(istream& in, Time& t);
    friend fstream& operator<<(fstream& fout, const Time& t);
    friend fstream& operator>>(fstream& fin, Time& t);
    Time operator+(const Time& other) const;
    bool operator==(const Time& other) const;
private:
    int minutes;
    int seconds;
    void normalize();
};
