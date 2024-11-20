#include<iostream>
using namespace std;
int main()
{
	float a, b, c;
	float *aP = &a, *bP = &b;

	cin >> a >> b;

	c = (*aP) + (*bP);

	cout << c;

	return 0;
}