//Вариант 9. Посчитать НОД для двух натуральных чисел.
#include<iostream>
#include<cmath>
using namespace std;
int dof(int a, int b) {
	if (b == 0) {
		return a;
	}

	return dof(b,a % b);

}

int main()
{
	int num1, num2,result;
	cin >> num1 >> num2;
	result = dof(num1, num2);

	cout << result;

	return 0;
}