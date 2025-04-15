﻿#include <iostream>
#include "Employee.h"
#include "Vector.h"

int main() {
    Vector employees(3);

    Employee* emp1 = new Employee("Ivanov Ivan", 35, "Manager", 50000.0);
    Employee* emp2 = new Employee("Petrova Anna", 28, "Developer", 70000.0);

    employees.add(emp1);
    employees.add(emp2);

    std::cout << employees;

    std::cout << "\nSalary with 15% bonus for " << emp1->getName()
        << ": " << emp1->calculateSalary(15) << std::endl;

    delete emp1;
    delete emp2;

    return 0;
}