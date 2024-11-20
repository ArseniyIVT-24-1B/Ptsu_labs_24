#include<iostream>
using namespace std;
int main()
{
	int minnum, maxnum, num, *numP,quantity;
	numP = &num;

	cin >> quantity;
	cin >> num;
	maxnum = *numP;
	minnum = *numP;

	for (int i = 1; i <= (quantity - 1); i++) {
		cin >> *numP;
		
		if (*numP > maxnum) {
			maxnum = *numP;
		}
		
		if (*numP < minnum) {
			minnum = *numP;
		}

	}
	cout << maxnum << " " << minnum;
	return 0;
}