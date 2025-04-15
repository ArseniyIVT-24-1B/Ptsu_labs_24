﻿#pragma once

class Pair
{
private:
    int first;
    double second;

public:
    Pair() : first(0), second(0.0) {}
    Pair(int first, double second) : first(first), second(second) {}
    Pair(const Pair& p) : first(p.first), second(p.second) {}

    bool operator>(const Pair& op) const;
    bool operator<(const Pair& op) const;
    bool operator==(const Pair& op) const;
    bool operator!=(const Pair& op) const;

    Pair& operator--();
    Pair operator--(int);

    ~Pair() {}
};
