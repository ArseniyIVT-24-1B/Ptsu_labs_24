﻿#include "Vector.h"
#include <iostream>

Vector::Vector() : size(0), current(0), data(nullptr) {}

Vector::Vector(int size) : size(size), current(0) {
    data = new Person * [size];
}

Vector::~Vector() {
    if (data != nullptr) {
        delete[] data;
    }
}

void Vector::add(Person* person) {
    if (current < size) {
        data[current++] = person;
    }
}

std::ostream& operator<<(std::ostream& out, const Vector& v) {
    if (v.current == 0) {
        out << "Empty vector!" << std::endl;
    }
    else {
        for (int i = 0; i < v.current; ++i) {
            v.data[i]->show();
            out << std::endl;
        }
    }
    return out;
}