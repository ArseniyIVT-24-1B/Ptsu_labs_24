#pragma once
#include <iostream> 
using namespace std;

class Time
{
public:
    Time operator+(Time k) const;
    Time operator+(int seconds) const;
    Time(void);
    Time(int, int);
    Time(const Time&);
    Time& operator=(const Time&);

    friend ostream& operator<< (ostream& out, const Time&);
    friend istream& operator>> (istream& in, Time&);

    virtual ~Time(void) {};
private:
    int min, sec;
};