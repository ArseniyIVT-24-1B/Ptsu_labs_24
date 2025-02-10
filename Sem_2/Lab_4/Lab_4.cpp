#include<iostream>
#include <cstdlib>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");

	// #1,2

	int range_min, range_max;
	int a[10];
	range_min = 2;
	range_max = 28000;

	cout << "Исходный массив:" << endl;

	for (int i = 0; i < 10; i++)
	{
		a[i] = ((double)rand() / RAND_MAX) * (range_max - range_min) + range_min;
		cout << a[i] << " ";
	}
	cout << endl;

	// #3

	int b[10];
	cout << "Введите значение для удаления: ";
	int deleteN;
	cin >> deleteN;
	bool flag1 = true;

	for (int i = 0; i < 10; i++)
	{
		if (flag1 == true) {
			if (a[i] == deleteN) {

				for (int j = i; j < 10 - i; j++) {
					b[j] = a[j + 1];
				}
				flag1 = false;
			}
			else { b[i] = a[i]; }
		}


	}
	if (flag1 == true) { cout << "В массиве нет такого числа!"; }
	cout << endl;

	int o;
	if (flag1 == true) { o = 10; }
	else { o = 9; }


	// #4
	int k;
	int c[10];
	cout << "Введите количество элементов для сдвига вправо: ";
	cin >> k;

	k = k % o;

	for (int i = 0; i < o; i++){
		
		c[(i + k) % o] = b[i];
	
	}
	
	
	//#5

	for (int i = 0; i < o; i++) { cout << c[i] << " "; }
	cout << endl;

	return 0;


}
