#pragma once
#include <iostream>
#include <stdexcept> // для std::out_of_range
using namespace std;

template <class T>
class Vector {
private:
    int size;
    T* data;

public:

    Vector(int s, T k) {
        size = s;
        data = new T[size];
        for (int i = 0; i < size; i++) {
            data[i] = k;
        }
    }

    Vector(const Vector<T>& a) {
        size = a.size;
        data = new T[size];
        for (int i = 0; i < size; i++) {
            data[i] = a.data[i];
        }
    }

    ~Vector() {
        delete[] data;
        data = nullptr;
    }


    Vector& operator=(const Vector<T>& a) {
        if (this == &a) return *this;
        size = a.size;
        delete[] data;
        data = new T[size];
        for (int i = 0; i < size; i++) {
            data[i] = a.data[i];
        }
        return *this;
    }

    T& operator[](int index) {
        if (index < size) return data[index];
        throw out_of_range("Index out of range");
    }

    Vector operator+(const T k) {
        Vector<T> temp(size, k);
        for (int i = 0; i < size; i++) {
            temp.data[i] = data[i] + k;
        }
        return temp;
    }

    int operator()() {
        return size;
    }


    T average() const {
        if (size == 0) throw logic_error("Empty vector");

        T sum = data[0];
        for (int i = 1; i < size; i++) {
            sum = sum + data[i];
        }
        return sum / size;
    }

    void insert(int pos, T k) {
        if (pos < 0 || pos > size) throw out_of_range("Invalid position");

        T* new_data = new T[size + 1];
        for (int i = 0; i < pos; i++) {
            new_data[i] = data[i];
        }
        new_data[pos] = k;
        for (int i = pos; i < size; i++) {
            new_data[i + 1] = data[i];
        }

        delete[] data;
        data = new_data;
        size++;
    }

    void remove_max() {
        if (size == 0) return;

        int max_pos = 0;
        for (int i = 1; i < size; i++) {
            if (data[i] > data[max_pos]) {
                max_pos = i;
            }
        }

        for (int i = max_pos; i < size - 1; i++) {
            data[i] = data[i + 1];
        }
        size--;
    }

    void divide_by_min() {
        if (size == 0) return;

        T min_val = data[0];
        for (int i = 1; i < size; i++) {
            if (data[i] < min_val) {
                min_val = data[i];
            }
        }

        if (min_val == T(0)) throw logic_error("Division by zero");

        for (int i = 0; i < size; i++) {
            data[i] = data[i] / min_val;
        }
    }

    friend ostream& operator<<(ostream& out, const Vector<T>& a) {
        for (int i = 0; i < a.size; i++) {
            out << a.data[i] << " ";
        }
        return out;
    }

    friend istream& operator>>(istream& in, Vector<T>& a) {
        for (int i = 0; i < a.size; i++) {
            in >> a.data[i];
        }
        return in;
    }
};