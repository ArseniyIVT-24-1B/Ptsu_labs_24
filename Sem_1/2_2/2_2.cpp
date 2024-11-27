#include<iostream>
using namespace std;
int main()
{
	int N,N2;
	N2 = 1;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		
		N2 *= i;
	
	}

	cout << N2;

	return 0;
}