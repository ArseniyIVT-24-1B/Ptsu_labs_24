﻿#include <iostream>
#include "Employee.h"

int main() {
    Employee emp("Ivanov Ivan", 35, "Manager", 50000.0);

    std::cout << "Employee: " << emp.getName() << std::endl;
    std::cout << "Age: " << emp.getAge() << std::endl;
    std::cout << "Position: " << emp.getPosition() << std::endl;
    std::cout << "Base salary: " << emp.getSalary() << std::endl;
    std::cout << "Salary with 15% bonus: " << emp.calculateSalary(15) << std::endl;

    return 0;
}