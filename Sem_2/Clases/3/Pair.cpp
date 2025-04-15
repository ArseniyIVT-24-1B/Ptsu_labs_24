﻿#include "Pair.h"

bool Pair::operator>(const Pair& op) const {
    return (first > op.first) || (first == op.first && second > op.second);
}

bool Pair::operator<(const Pair& op) const {
    return (first < op.first) || (first == op.first && second < op.second);
}

bool Pair::operator==(const Pair& op) const {
    return (first == op.first) && (second == op.second);
}

bool Pair::operator!=(const Pair& op) const {
    return !(*this == op);
}

Pair& Pair::operator--() {
    --first;
    return *this;
}

Pair Pair::operator--(int) {
    Pair temp = *this;
    second -= 1.0;
    return temp;
}