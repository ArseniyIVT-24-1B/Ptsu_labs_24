#include <iostream>
#include "equation.h"
void equation::Init(double A, double B)
{
	first = A;
	second = B;
}
void equation::Read()
{
	std::cout << "\nType A and B coefficents\n";
	std::cin >> first >> second;
}
void equation::Show()
{
	std::cout << "Equation is y = " << first << "x + " << second << std::endl;
}
double equation::Function(double x)
{
	return first * x + second;
}