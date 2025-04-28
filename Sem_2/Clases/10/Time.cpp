#include "Time.h"

Time::Time() : minutes(0), seconds(0) {}

Time::Time(int m, int s) : minutes(m), seconds(s) {
    normalize();
}

Time::Time(const Time& t) : minutes(t.minutes), seconds(t.seconds) {}

Time Time::operator=(const Time& t) {
    if (this != &t) {
        minutes = t.minutes;
        seconds = t.seconds;
    }
    return *this;
}

void Time::normalize() {
    minutes += seconds / 60;
    seconds %= 60;
    if (seconds < 0) {
        minutes -= 1;
        seconds += 60;
    }
}

Time Time::operator+(const Time& other) const {
    return Time(minutes + other.minutes, seconds + other.seconds);
}

bool Time::operator==(const Time& other) const {
    return (minutes == other.minutes) && (seconds == other.seconds);
}

ostream& operator<<(ostream& out, const Time& t) {
    out << t.minutes << ":" << (t.seconds < 10 ? "0" : "") << t.seconds;
    return out;
}

istream& operator>>(istream& in, Time& t) {
    char colon;
    in >> t.minutes >> colon >> t.seconds;
    t.normalize();
    return in;
}

fstream& operator<<(fstream& fout, const Time& t) {
    fout << t.minutes << " " << t.seconds << endl;
    return fout;
}

fstream& operator>>(fstream& fin, Time& t) {
    fin >> t.minutes >> t.seconds;
    t.normalize();
    return fin;
}