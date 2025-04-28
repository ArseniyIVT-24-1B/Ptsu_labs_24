#pragma once
#include "Object.h"

class Person : public Object {
public:
    Person(void);
    virtual ~Person(void);
    void Show();
    void Input();
    void HandleEvent(const int& e);
    Person(string, int);
    Person(const Person&);

    string Get_name() { return name; }
    int Get_age() { return age; }
    void Set_name(string);
    void Set_age(int);

    Person& operator=(const Person&);
protected:
    string name;
    int age;
};
