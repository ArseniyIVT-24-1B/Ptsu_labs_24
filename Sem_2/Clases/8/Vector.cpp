#include "Vector.h"
#include "Person.h"
#include "Student.h"
#include <iostream>

Vector::Vector(int n) {
    beg = new Object * [n];
    cur = 0;
    size = n;
}

Vector::~Vector(void) {
    if (beg != 0) delete[] beg;
    beg = 0;
}

void Vector::Add() {
    if (cur < size) {
        cout << "1. Person" << endl;
        cout << "2. Student" << endl;
        int y;
        cin >> y;

        Object* p;
        if (y == 1) {
            Person* a = new Person();
            a->Input();
            p = a;
        }
        else {
            Student* b = new Student();
            b->Input();
            p = b;
        }

        beg[cur] = p;
        cur++;
    }
}

void Vector::Del() {
    if (cur == 0) return;
    cur--;
}

void Vector::Show() {
    if (cur == 0) cout << "Empty" << endl;
    Object** p = beg;
    for (int i = 0; i < cur; i++) {
        (*p)->Show();
        p++;
    }
}

void Vector::ShowOne(int index) {
    if (index >= 0 && index < cur) {
        beg[index]->Show();
    }
}

int Vector::operator()() {
    return cur;
}

void Vector::HandleEvent(const TEvent& e) {
    if (e.what == evMessage) {
        Object** p = beg;
        for (int i = 0; i < cur; i++) {
            (*p)->HandleEvent(e.command);
            p++;
        }
    }
}