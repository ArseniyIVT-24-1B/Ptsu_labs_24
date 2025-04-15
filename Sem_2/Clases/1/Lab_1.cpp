#include <iostream>
#include "equation.h"
int main()
{
	equation A, B;
	A.Init(4.0, 54);
	B.Read();
	A.Show();
	B.Show();
	std::cout << A.Function(45) << std::endl;
	std::cout << B.Function(10) << std::endl;
}