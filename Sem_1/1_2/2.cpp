#include <iostream>
using namespace std;
int main() {
	float a, b;
	cin >> a >> b;
	if (b == 0) {
		cout << "Error";
	}
	else {
		float c = a / b;
		cout << c;
	}
	return 0;
}