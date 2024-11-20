#include<iostream>
using namespace std;
int main()
{
	int a, b, cP;
	int *aP;
	int *bP;
	aP = &a;
	bP = &b;

	cin >> a >> b;
	
	cout << a << " " << b << endl;

	cP = *aP;
	a = *bP;
	b = cP;

	cout << a << " " << b << endl;

	return 0;
}