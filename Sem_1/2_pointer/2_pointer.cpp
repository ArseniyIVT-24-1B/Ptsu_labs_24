#include<iostream>
using namespace std;
int main()
{
	int a, b;
	int *aP;
	int *bP;
	aP = &a;
	bP = &b;

	cin >> a >> b;
	
	int c = (*aP) + (*bP);

	cout << c << endl;

	return 0;
}