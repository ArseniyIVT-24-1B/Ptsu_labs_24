#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

void printVector(const vector<double>& vec) 
{
	for (double num:vec) 
	{
		cout << num << " ";
	}
	cout << endl;
}

int main() 
{	
	setlocale(LC_ALL, "Ru");
	vector<double> numbers;

	cout << "Введите размер контейнера: " << endl;
	int N;
	cin >> N;

	cout << "Введите значение вконтейнера" << endl;

	for (int i = 0; i < N; i++) 
	{
		double num;
		cin >> num;
		numbers.push_back(num);
	}

	cout << "Ваш контейнер: " << endl;

	printVector(numbers);

	double sum = accumulate(numbers.begin(), numbers.end(), 0.0);
	double average = sum / numbers.size();

	cout << "Среденне значение: " << endl << average << endl;

	int k;
	cout << "Введите позицию, куда хотите поместить среднее значение" << endl;
	cin >> k;
	if (k >= 0 && k <= numbers.size()) 
	{
		numbers.insert(numbers.begin() + k - 1, average);
		cout << "Контейнер после вставки:" << endl;
		printVector(numbers);
	}
	else 
	{
		cout << "Неправильная позиция!" << endl;
	}

	auto max_it = max_element(numbers.begin(), numbers.end());

	if (max_it != numbers.end()) 
	{
		numbers.erase(max_it);
		cout << "Контейнер, после удаления элемента с максимальным значением" << endl;
		printVector(numbers);
	}

	if (!numbers.empty()) 
	{
		double min_val = *min_element(numbers.begin(), numbers.end());
		if (min_val != 0) 
		{
			for (double& num : numbers) 
			{
				num /= min_val;
			}
			cout << "Конетейнер, после деления на минимальный элемент: " << endl;
			printVector(numbers);
		}
		else 
		{
			cout << "Нельзя делить на ноль!";
		}
	}

	return 0;
}