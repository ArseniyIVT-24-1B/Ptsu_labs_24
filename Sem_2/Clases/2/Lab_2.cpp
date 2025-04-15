#include <iostream>
#include <string>
#include "Computer.h"
Computer makecomp()
{
	std::string a;
	int b;
	int c;
	std::cin >> a >> b >> c;
	Computer t(a, b, c);
	return t;
}
int main()
{
	Computer c1;
	c1.show();
	Computer c2;
	c2.show();
	Computer c3 = c2;
	c3.set_cpu("Ryazen 5 5600");
	c3.set_ram(64);
	c3.set_hdd(5000);
	c1 = makecomp();
	c1.show();
}