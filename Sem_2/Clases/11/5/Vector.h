#pragma once
#include <stack>
#include <vector>
#include <numeric>
#include <stdexcept>
#include<iostream>

template <typename T>
class Vector {
private:
    std::stack<T> data;

public:

    void push(const T& value) {
        data.push(value);
    }


    T average() const {
        if (data.empty()) {
            throw std::runtime_error("Cannot calculate average of empty vector");
        }

        std::vector<T> elements;
        std::stack<T> temp = data;

        while (!temp.empty()) {
            elements.push_back(temp.top());
            temp.pop();
        }

        T sum = std::accumulate(elements.begin(), elements.end(), T());
        return sum / elements.size();
    }


    void addAverageToElements() {
        if (data.empty()) return;

        T avg = average();
        std::vector<T> elements;

        while (!data.empty()) {
            elements.push_back(data.top() + avg);
            data.pop();
        }

        for (auto it = elements.rbegin(); it != elements.rend(); ++it) {
            data.push(*it);
        }
    }

    void print() const {
        if (data.empty()) {
            std::cout << "Vector is empty" << std::endl;
            return;
        }

        std::stack<T> temp = data;
        std::vector<T> elements;

        while (!temp.empty()) {
            elements.push_back(temp.top());
            temp.pop();
        }

        for (auto it = elements.rbegin(); it != elements.rend(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    }
};