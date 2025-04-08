#include <iostream>
using namespace std;

//Сформировать одномерный массив Удалить из него элемент с заданным номером, добавить элемент с заданным номером;

int main() {

	setlocale(LC_ALL, "RU");

	int N;
	cout << "Введите количество элементов массива: ";
	cin >> N;

	int* array = new int[N];
	int r, range_min, range_max; range_min = 2; 
	range_max = 280000; 
	for (int i = 0; i < N; i++) { 
		array[i] = ((double)rand() / RAND_MAX) * (range_max - range_min) + range_min; 
		cout << array[i] << " "; 
	}

	cout << endl << "Введите номер элемента который хотите удалить:";
	int del;
	cin >> del;
	del - 1;

	int* array2 = new int[N - 1];

	for (int i = 0; i < N - 1; i++) {
		if (i < del - 1) {
			array2[i] = array[i];
		}
		else {
			array2[i] = array[i + 1];
		}
	}
	delete[] array;

	cout << "Изменёный массив:" << endl;
	for (int i = 0; i < N - 1; i++) {
		cout << array2[i] << " ";
	}

	cout << endl << "Введите номер и значение индекса, который надо заменить:" << endl;

	int index, value;
	cin >> index;
	index;
	cin >> value;

	array2[index - 1] = value;

	cout << "Исходный массив: ";

	for (int i = 0; i < N - 1; i++) {
		cout << array2[i] << " ";
	}

	return 0;
}