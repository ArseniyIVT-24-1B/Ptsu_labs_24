#pragma once
#include <string>
#include <iostream>
using namespace std;

class error {
    string message;
public:
    error(string msg) : message(msg) {}
    void print() { cout << message << endl; }
};
