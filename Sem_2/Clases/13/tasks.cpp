#include "tasks.h"
#include "money.h"
#include "my_vector.h"
#include <deque>
#include <set>
#include <algorithm>
#include <iostream>

void task1() {
    std::cout << "\n=== Task 1 ===" << std::endl;
    std::deque<Money> dm = { Money(10,50), Money(5,75), Money(15,25), Money(10,50) };
    std::cout << "Original: ";

    std::for_each(dm.begin(), dm.end(), [](const Money& m) { std::cout << m << " "; });
    std::cout << std::endl;

    std::replace(dm.begin(), dm.end(), Money(10, 50), Money(20, 00));
    std::cout << "Replace 10,50 with 20,00: \n";
    std::for_each(dm.begin(), dm.end(), [](const Money& m) { std::cout << m << " "; });
    std::cout << std::endl;

    dm.erase(std::remove(dm.begin(), dm.end(), Money(5, 75)), dm.end());
    std::cout << "Delete 5,75: \n";
    std::for_each(dm.begin(), dm.end(), [](const Money& m) { std::cout << m << " "; });
    std::cout << std::endl;

    std::sort(dm.begin(), dm.end());
    std::cout << "Sorted ascending : \n";
    std::for_each(dm.begin(), dm.end(), [](const Money& m) { std::cout << m << " "; });
    std::cout << std::endl;

    std::sort(dm.begin(), dm.end(), std::greater<Money>());
    std::cout << "Sorted descending:\n";
    std::for_each(dm.begin(), dm.end(), [](const Money& m) { std::cout << m << " "; });
    std::cout << std::endl;

    auto it = std::find(dm.begin(), dm.end(), Money(15, 25));
    if (it != dm.end()) {
        std::cout << "Element found: " << *it << std::endl;
    }

    if (!dm.empty()) {
        Money max_val = *std::max_element(dm.begin(), dm.end());
        dm.push_back(max_val);
        std::cout << "After adding max:\n";
        std::for_each(dm.begin(), dm.end(), [](const Money& m) { std::cout << m << " "; });
        std::cout << std::endl;
    }
}

void task2() {
    std::cout << "\n=== Task 2 ===" << std::endl;
    MyVector<Money> mv;
    mv.add(Money(10, 50)); mv.add(Money(5, 75)); mv.add(Money(15, 25));

    std::cout << "Original:\n";
    mv.print();

    mv.addAverageToEach();
    std::cout << "After adding mean:\n";
    mv.print();
    std::cout << "Sorted ascending:\n";
    mv.sortAscending();
    mv.print();
    std::cout << "Sorted descending:\n";
    mv.sortDescending();
    mv.print();
}

void task3() {
    std::cout << "\n=== Task 3 ===" << std::endl;
    std::set<Money> sm = { Money(10,50), Money(5,75), Money(15,25) };
    std::cout << "Original: ";
    std::for_each(sm.begin(), sm.end(), [](const Money& m) { std::cout << m << " "; });
    std::cout << std::endl;

    sm.erase(Money(5, 75));
    std::cout << "After deleting 5,75:\n";
    std::for_each(sm.begin(), sm.end(), [](const Money& m) { std::cout << m << " "; });
    std::cout << std::endl;

    auto it = sm.find(Money(10, 50));
    if (it != sm.end()) {
        std::cout << "Element found: " << *it << std::endl;
    }

    if (!sm.empty()) {
        Money max_val = *sm.rbegin();
        sm.insert(max_val);
        std::cout << "After adding max:\n";
        std::for_each(sm.begin(), sm.end(), [](const Money& m) { std::cout << m << " "; });
        std::cout << std::endl;
    }
}