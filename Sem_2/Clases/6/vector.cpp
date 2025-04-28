#include <iostream>
#include "vector.h"

Vector::Vector(int s, int k) 
{
    size = s;
    data = new int[size];
    for (int i = 0; i < size; i++) 
    {
        data[i] = k;
    }

    beg = Iterator{ &data[0] };
    end = Iterator{ &data[size] };
}

Vector::Vector(const Vector& a) 
{
    size = a.size;
    data = new int[size];
    for (int i = 0; i < size; i++) 
    {
        data[i] = a.data[i];
    }

    beg = a.beg; 
    end = a.end;
}

Vector::~Vector() 
{
    delete[] data;
    data = nullptr;
}

Vector& Vector::operator=(const Vector& a) 
{
    if (this == &a) 
    {
        return *this;
    }
    size = a.size;
    delete[] data;
    data = new int[size];
    for (int i = 0; i < size; i++) 
    {
        data[i] = a.data[i];
    }

    beg = a.beg; 
    end = a.end;

    return *this;
}

int& Vector::operator[](int index) 
{
    if (index >= size) 
    {
        std::cerr << "\nError! Index >= size\n";
        exit(1);
    }
    return data[index];
}

Vector Vector::operator+(int k) 
{
    Vector temp(size);
    for (int i = 0; i < size; ++i) 
    {
        temp.data[i] = data[i] + k;
    }
    return temp;
}

int Vector::operator()() 
{
    return len();
}

int Vector::len() const 
{
    return size;
}

std::ostream& operator<<(std::ostream& out, const Vector& a) 
{
    for (int i = 0; i < a.len(); ++i) 
    {
        out << a.data[i] << " ";
    }
    return out;
}

std::istream& operator>>(std::istream& in, Vector& a) 
{
    for (int i = 0; i < a.len(); ++i) 
    {
        in >> a.data[i];
    }
    return in;
}