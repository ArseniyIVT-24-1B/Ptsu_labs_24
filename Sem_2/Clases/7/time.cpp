#include "Time.h" 

Time::Time(void)
{
    min = sec = 0;
}

Time::Time(int M, int S)
{
    min = M;
    sec = S;
}

Time::Time(const Time& t)
{
    min = t.min;
    sec = t.sec;
}

Time& Time::operator =(const Time& t)
{
    min = t.min;
    sec = t.sec;
    return *this;
}

ostream& operator<<(ostream& out, const Time& t)
{
    out << t.min << ":" << t.sec;
    return out;
}

istream& operator>>(istream& in, Time& t)
{
    cout << "min? ";
    in >> t.min;
    cout << "sec? ";
    in >> t.sec;
    return in;
}

Time Time::operator+(Time k) const
{
    int t = min * 60 + sec;
    int kt = k.min * 60 + k.sec;
    t += kt;
    return Time(t / 60, t % 60);
}

Time Time::operator+(int seconds) const
{
    int total = min * 60 + sec + seconds;
    return Time(total / 60, total % 60);
}