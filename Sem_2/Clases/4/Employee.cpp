﻿#include "Employee.h"

Employee::Employee(const std::string& name, int age,
    const std::string& position, double salary)
    : Person(name, age), position(position), salary(salary) {}

void Employee::setPosition(const std::string& position) {
    this->position = position;
}

const std::string& Employee::getPosition() const {
    return position;
}

void Employee::setSalary(double salary) {
    this->salary = salary;
}

double Employee::getSalary() const {
    return salary;
}

double Employee::calculateSalary(double bonusPercent) const {
    return salary + (salary * bonusPercent / 100);
}