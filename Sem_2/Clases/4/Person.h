﻿#pragma once
#include <string>

class Person {
private:
    std::string name;
    int age;
public:
    Person(const std::string& name, int age);
    void setName(const std::string& name);
    const std::string& getName() const;
    void setAge(int age);
    int getAge() const;
    virtual ~Person() {}
};