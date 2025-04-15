#pragma once
#include <iostream>
#include <string>
class Computer
{
public:
	std::string cpu;
	int ram;
	int hdd;
	Computer();
	Computer(std::string, int, int);
	Computer(const Computer&);
	~Computer();
	std::string get_cpu();
	void set_cpu(std::string);
	int get_ram();
	void set_ram(int);
	int get_hdd();
	void set_hdd(int);
	void show();
};
