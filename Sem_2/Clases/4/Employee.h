﻿#pragma once
#include "Person.h"

class Employee : public Person {
private:
    std::string position;
    double salary;
public:
    Employee(const std::string& name, int age, const std::string& position, double salary);
    void setPosition(const std::string& position);
    const std::string& getPosition() const;
    void setSalary(double salary);
    double getSalary() const;
    double calculateSalary(double bonusPercent) const;
};
