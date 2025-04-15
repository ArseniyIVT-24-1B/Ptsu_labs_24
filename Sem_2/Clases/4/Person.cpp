﻿#include "Person.h"

Person::Person(const std::string& name, int age) : name(name), age(age) {}

void Person::setName(const std::string& name) {
    this->name = name;
}

const std::string& Person::getName() const {
    return name;
}

void Person::setAge(int age) {
    this->age = age;
}

int Person::getAge() const {
    return age;
}