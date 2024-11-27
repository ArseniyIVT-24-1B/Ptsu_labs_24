#include<iostream>
using namespace std;
int main()
{
	int N, tmp, sum = 0;

	cin >> N;
	
	for (int i = 1; i <= N; i++) {
		
		tmp = 1;
		for (int j = i; j <= 2*i; j++) {

			tmp *= j;

		}

		sum += tmp;

	}
	cout << sum << endl;

	return 0;
}