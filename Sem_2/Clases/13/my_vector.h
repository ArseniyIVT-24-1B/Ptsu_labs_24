#pragma once
#include <vector>
#include <algorithm>
#include <numeric>
#include <iostream>

template<typename T>
class MyVector {
    std::vector<T> data;

public:
    void add(const T& item);
    void replaceAll(const T& old_val, const T& new_val);
    void removeAll(const T& val);
    void sortAscending();
    void sortDescending();
    void addAverageToEach();
    void print() const;
};

template<typename T>
void MyVector<T>::add(const T& item) {
    data.push_back(item);
}

template<typename T>
void MyVector<T>::replaceAll(const T& old_val, const T& new_val) {
    std::replace(data.begin(), data.end(), old_val, new_val);
}

template<typename T>
void MyVector<T>::removeAll(const T& val) {
    data.erase(std::remove(data.begin(), data.end(), val), data.end());
}

template<typename T>
void MyVector<T>::sortAscending() {
    std::sort(data.begin(), data.end());
}

template<typename T>
void MyVector<T>::sortDescending() {
    std::sort(data.begin(), data.end(), std::greater<T>());
}

template<typename T>
void MyVector<T>::addAverageToEach() {
    if (data.empty()) return;
    T sum = std::accumulate(data.begin(), data.end(), T());
    T avg = sum / static_cast<int>(data.size());
    for_each(data.begin(), data.end(), [avg](T& item) { item = item + avg; });
}

template<typename T>
void MyVector<T>::print() const {
    for_each(data.begin(), data.end(), [](const T& item) { std::cout << item << " "; });
    std::cout << std::endl;
}
