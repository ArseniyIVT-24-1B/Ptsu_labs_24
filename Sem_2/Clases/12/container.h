#pragma once
#include <set>
#include <numeric>
#include <iostream>

template <typename T>
class MyAssocContainer {
    std::set<T> data;

public:
    void add(const T& item);
    void addAverageToEach();
    void print() const;
};

template <typename T>
void MyAssocContainer<T>::add(const T& item) {
    data.insert(item);
}

template <typename T>
void MyAssocContainer<T>::addAverageToEach() {
    if (data.empty()) return;

    T sum = std::accumulate(data.begin(), data.end(), T());
    T avg = sum / static_cast<int>(data.size());

    std::set<T> newData;
    for (const auto& item : data) {
        newData.insert(item + avg);
    }
    data = std::move(newData);
}

template <typename T>
void MyAssocContainer<T>::print() const {
    for (const auto& item : data) {
        std::cout << item << " ";
    }
    std::cout << std::endl;
}
