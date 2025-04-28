#include "Person.h"
#include <iostream>

Person::Person(void) {
    name = "";
    age = 0;
}

Person::~Person(void) {}

Person::Person(string n, int a) {
    name = n;
    age = a;
}

Person::Person(const Person& p) {
    name = p.name;
    age = p.age;
}

void Person::Set_name(string n) {
    name = n;
}

void Person::Set_age(int a) {
    age = a;
}

Person& Person::operator=(const Person& p) {
    if (&p == this) return *this;
    name = p.name;
    age = p.age;
    return *this;
}

void Person::Show() {
    cout << "\nNAME: " << name;
    cout << "\nAGE: " << age;
    cout << "\n";
}

void Person::Input() {
    cout << "\nName: ";
    cin >> name;
    cout << "\nAge: ";
    cin >> age;
}

void Person::HandleEvent(const int& e) {
    if (e == 3) {
        cout << "name=" << Get_name() << endl;
    }
}