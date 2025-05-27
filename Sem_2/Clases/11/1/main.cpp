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

	cout << "������� ������ ����������: " << endl;
	int N;
	cin >> N;

	cout << "������� �������� �����������" << endl;

	for (int i = 0; i < N; i++) 
	{
		double num;
		cin >> num;
		numbers.push_back(num);
	}

	cout << "��� ���������: " << endl;

	printVector(numbers);

	double sum = accumulate(numbers.begin(), numbers.end(), 0.0);
	double average = sum / numbers.size();

	cout << "�������� ��������: " << endl << average << endl;

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
		double min_val = *min_element(numbers.begin(), numbers.end());
		if (min_val != 0) 
		{
			for (double& num : numbers) 
			{
				num /= min_val;
			}
			cout << "����������, ����� ������� �� ����������� �������: " << endl;
			printVector(numbers);
		}
		else 
		{
			cout << "������ ������ �� ����!";
		}
	}

	return 0;
}