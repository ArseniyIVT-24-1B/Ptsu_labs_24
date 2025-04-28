#pragma once
#include "Person.h"

class Student : public Person {
public:
    Student(void);
    ~Student(void);
    void Show();
    void Input();
    Student(string, int, float);
    Student(const Student&);

    float Get_rating() { return rating; }
    void Set_rating(float);

    Student& operator=(const Student&);
protected:
    float rating;
};