#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include "Time.h"

using namespace std;

void printVector(const vector<Time>& vec) 
{
	for (Time num:vec) 
	{
		cout << num << " ";
	}
	cout << endl;
}

Time calculateAverageTime(const vector<Time>& times) {
	if (times.empty()) return Time(0, 0);

	Time total(0, 0);
	for (const Time& t : times) {
		total = total + t;
	}
	int avg_sec = (total.get_min() * 60 + total.get_sec()) / times.size();
	return Time(avg_sec / 60, avg_sec % 60);
}

int main()
{
	setlocale(LC_ALL, "Ru");
	vector<Time> numbers;

	cout << "Введите размер контейнера: " << endl;
	int N;
	cin >> N;

	cout << "Введите значение вконтейнера" << endl;

	for (int i = 0; i < N; i++)
	{
		Time t;
		cin >> t;
		numbers.push_back(t);
	}

	cout << "Ваш контейнер: " << endl;

	printVector(numbers);

	Time average = calculateAverageTime(numbers);
	cout << "Среднее время: " << average << endl;


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
		auto minIt = min_element(numbers.begin(), numbers.end(),
			[](const Time& a, const Time& b) {
				return (a.get_min() * 60 + a.get_sec()) < (b.get_min() * 60 + b.get_sec());
			});
		Time minTime = *minIt;

		if (minTime.get_min() != 0 || minTime.get_sec() != 0) 
		{
			for (Time& t : numbers) {
				int totalSec = t.get_min() * 60 + t.get_sec();
				int minTotalSec = minTime.get_min() * 60 + minTime.get_sec();
				int newSec = totalSec / minTotalSec;
				t = Time(0, newSec);
			}
			cout << "Контейнер после деления на минимальное число: ";
			printVector(numbers);
		}
		else 
		{
			cout << "На ноль делить нельзя!" << endl;
		}
	}
	
	return 0;
}