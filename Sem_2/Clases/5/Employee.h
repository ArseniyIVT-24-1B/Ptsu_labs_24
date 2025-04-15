﻿#pragma once
#include "Person.h"

class Employee : public Person {
private:
    std::string position;
    double salary;
public:
    Employee();
    Employee(const std::string& name, int age,
        const std::string& position, double salary);

    void setPosition(const std::string& position);
    void setSalary(double salary);
    const std::string& getPosition() const;
    double getSalary() const;
    double calculateSalary(double bonusPercent) const;

    void setName(const std::string& name) override;
    void setAge(int age) override;
    const std::string& getName() const override;
    int getAge() const override;
    void show() const override;
};
