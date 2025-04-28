#pragma once
#include "Object.h"
#include "Event.h"

class Vector {
public:
    Vector(int);
    ~Vector(void);
    void Add();
    void Del();
    void Show();
    void ShowOne(int);
    int operator()();
    void HandleEvent(const TEvent& e);
protected:
    Object** beg;
    int size;
    int cur;
};