#pragma once
#include <string>
using namespace std;

class Object {
public:
    Object(void);
    virtual void Show() = 0;
    virtual void Input() = 0;
    virtual void HandleEvent(const int& e) = 0;
    virtual ~Object(void);
};