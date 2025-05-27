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

	cout << "������� ������ ����������: " << endl;
	int N;
	cin >> N;

	cout << "������� �������� �����������" << endl;

	for (int i = 0; i < N; i++)
	{
		Time t;
		cin >> t;
		numbers.push_back(t);
	}

	cout << "��� ���������: " << endl;

	printVector(numbers);

	Time average = calculateAverageTime(numbers);
	cout << "������� �����: " << average << endl;


	int k;
	cout << "������� �������, ���� ������ ��������� ������� ��������" << endl;
	cin >> k;
	if (k >= 0 && k <= numbers.size())
	{
		numbers.insert(numbers.begin() + k - 1, average);
		cout << "��������� ����� �������:" << endl;
		printVector(numbers);
	}
	else
	{
		cout << "������������ �������!" << endl;
	}

	auto max_it = max_element(numbers.begin(), numbers.end());

	if (max_it != numbers.end())
	{
		numbers.erase(max_it);
		cout << "���������, ����� �������� �������� � ������������ ���������" << endl;
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
			cout << "��������� ����� ������� �� ����������� �����: ";
			printVector(numbers);
		}
		else 
		{
			cout << "�� ���� ������ ������!" << endl;
		}
	}
	
	return 0;
}