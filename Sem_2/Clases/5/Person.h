﻿#pragma once
#include <string>

class Person {
protected:
    std::string name;
    int age;
public:
    Person() : name(""), age(0) {}
    Person(const std::string& name, int age) : name(name), age(age) {}
    virtual ~Person() {}

    virtual void setName(const std::string& name) = 0;
    virtual void setAge(int age) = 0;
    virtual const std::string& getName() const = 0;
    virtual int getAge() const = 0;
    virtual void show() const = 0;
};
