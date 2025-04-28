#pragma once
#include <iostream>

class Iterator {
public:
    Iterator() : elem(nullptr) {}
    Iterator(int* p) : elem(p) {}
    Iterator(const Iterator& it) : elem(it.elem) {}

    bool operator==(const Iterator& it) const { return elem == it.elem; }
    bool operator!=(const Iterator& it) const { return elem != it.elem; }
    Iterator& operator++() { ++elem; return *this; }
    Iterator& operator--() { --elem; return *this; }
    int& operator*() const { return *elem; }

private:
    int* elem;
};

class Vector {
public:
    Vector(int s, int k = 0);
    Vector(const Vector& a);
    ~Vector();
    Vector& operator=(const Vector& a);
    int& operator[](int index);
    Vector operator+(int k);
    int operator()();
    int len() const;

    Iterator first() { return beg; }
    Iterator last() { return end; }

    friend std::ostream& operator<<(std::ostream& out, const Vector& a);
    friend std::istream& operator>>(std::istream& in, Vector& a);

private:
    int size;
    int* data;
    Iterator beg;
    Iterator end;
};