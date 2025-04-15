#include <iostream>
#include <string>
#include "Computer.h"

Computer::Computer()
{
	cpu = "";
	ram = 0;
	hdd = 0;
}
Computer::Computer(std::string a, int b, int c)
{
	cpu = a;
	ram = b;
	hdd = c;
	std::cout <<  this << std::endl;
}
Computer::Computer(const Computer& a)
{
	cpu = a.cpu;
	ram = a.ram;
	hdd = a.hdd;
}
Computer::~Computer()
{
	std::cout << this << std::endl;
}
std::string Computer::get_cpu()
{
	return cpu;
}
int Computer::get_ram()
{
	return ram;
}
int Computer::get_hdd()
{
	return hdd;
}
void Computer::set_cpu(std::string N)
{
	cpu = N;
}
void Computer::set_ram(int N)
{
	ram = N;
}
void Computer::set_hdd(int N)
{
	hdd = N;
}void Computer::show()
{
	std::cout << cpu << ram << hdd;
}