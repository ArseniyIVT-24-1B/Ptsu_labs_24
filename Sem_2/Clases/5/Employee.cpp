﻿#include "Employee.h"
#include <iostream>

Employee::Employee() : Person(), position(""), salary(0.0) {}

Employee::Employee(const std::string& name, int age,
    const std::string& position, double salary)
    : Person(name, age), position(position), salary(salary) {}

void Employee::setPosition(const std::string& position) {
    this->position = position;
}

void Employee::setSalary(double salary) {
    this->salary = salary;
}

const std::string& Employee::getPosition() const {
    return position;
}

double Employee::getSalary() const {
    return salary;
}

double Employee::calculateSalary(double bonusPercent) const {
    return salary + (salary * bonusPercent / 100);
}

void Employee::setName(const std::string& name) {
    this->name = name;
}

void Employee::setAge(int age) {
    this->age = age;
}

const std::string& Employee::getName() const {
    return name;
}

int Employee::getAge() const {
    return age;
}

void Employee::show() const {
    std::cout << "Name: " << name << "\n"
        << "Age: " << age << "\n"
        << "Position: " << position << "\n"
        << "Salary: " << salary << std::endl;
}