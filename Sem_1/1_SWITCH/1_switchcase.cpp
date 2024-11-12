#include<iostream>
using namespace std;
int main()
{
	float a, b;
	int c;
	cin >> a >> b >> c;
	switch(c){
	case 1: cout << a + b; break;
	case 2: cout << a - b; break;
	case 3: cout << a * b; break;
	case 4: {
		if (b == 0) {
			cout << "Error"; break;
		}
		else {
			cout << a / b; break;
		}
	}
	default: cout << "Error";
	}


	return 0;
}