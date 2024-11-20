#include<iostream>
using namespace std;
int main()
{
	int num, fact=1;
	int *factP = &fact;

	cin >> num;

	for (int i = 1; i <= num; i++) {
		*factP *= i;
	}
	
	cout << fact;

	return 0;
}