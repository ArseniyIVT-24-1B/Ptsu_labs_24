﻿#pragma once
#include "Person.h"

class Vector {
private:
    int size;
    int current;
    Person** data;
public:
    Vector();
    Vector(int size);
    ~Vector();

    void add(Person* person);
    friend std::ostream& operator<<(std::ostream& out, const Vector& v);
};
