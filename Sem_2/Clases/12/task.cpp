#include "task.h"
#include "money.h"
#include "container.h"
#include <set>
#include <iostream>

void task1() {
    std::cout << "\n=== Task 1: Integer Set Operations ===" << std::endl;

    std::set<int> numbers = { 5, 2, 8, 3, 1 };

    std::cout << "Original set: ";
    for (int n : numbers) std::cout << n << " ";
    std::cout << std::endl;

    if (!numbers.empty()) {
        int max_val = *numbers.rbegin();
        numbers.insert(max_val);
    }

    std::cout << "After adding max element: ";
    for (int n : numbers) std::cout << n << " ";
    std::cout << std::endl;
}

void task2() {
    std::cout << "\n=== Task 2: Money Set Operations ===" << std::endl;

    std::set<Money> moneySet = { Money(10, 50), Money(5, 75), Money(15, 25) };

    std::cout << "Original money set: ";
    for (const Money& m : moneySet) std::cout << m << " ";
    std::cout << std::endl;

    Money toRemove(5, 75);
    moneySet.erase(toRemove);

    std::cout << "After removing " << toRemove << ": ";
    for (const Money& m : moneySet) std::cout << m << " ";
    std::cout << std::endl;
}

void task3() {
    std::cout << "\n=== Task 3: Template Container Demonstration ===" << std::endl;

    MyAssocContainer<int> intContainer;
    intContainer.add(10);
    intContainer.add(20);
    intContainer.add(30);

    std::cout << "Integer container before modification: ";
    intContainer.print();

    intContainer.addAverageToEach();
    std::cout << "Integer container after adding average: ";
    intContainer.print();

    MyAssocContainer<Money> moneyContainer;
    moneyContainer.add(Money(10, 50));
    moneyContainer.add(Money(20, 75));

    std::cout << "Money container before modification: ";
    moneyContainer.print();

    moneyContainer.addAverageToEach();
    std::cout << "Money container after adding average: ";
    moneyContainer.print();
}