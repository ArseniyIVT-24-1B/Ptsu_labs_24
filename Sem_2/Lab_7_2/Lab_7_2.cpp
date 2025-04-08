#include <iostream>
using namespace std;

//Написать функцию sum с переменным числом параметров, которая находит сумму чисел типа int. 
//Написать вызывающую функцию main, которая обращается к функции sum не менее трех раз с количеством параметров 3, 7, 11.

int sum(int a) {
	return a;
}

int sum(int a, int b) {
	return a + b;
}

template<typename... Args>
int sum(int first, Args... args) {
	return first + sum(args...);
}


int main() {
	
	cout << sum(1, 2, 3) << endl;
	cout << sum(23, 45, 1, 0, 0, 0, 1) << endl;
	cout << sum(56, 12, 54, 4, 2, 67, 8, 47, 12, 7, 6) << endl;
	
	return 0;
}