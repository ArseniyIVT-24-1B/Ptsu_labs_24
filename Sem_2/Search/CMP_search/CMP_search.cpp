﻿#include <iostream>
#include <string>
using namespace std;

void prefix(string substr, int substrSize, int* pref);

void KMPSearch(string substr, string str)
{
	int strSize = str.size();
	int substrSize = substr.size();

	int* pref = new int[substrSize];

	prefix(substr, substrSize, pref);

	int i = 0;
	int j = 0;

	while ((strSize - i) >= (substrSize - j))
	{
		if (substr[j] == str[i])
		{
			j++;
			i++;
		}

		if (j == substrSize)
		{
			cout << "Подстрока найдена:" << i - j << endl;
			j = pref[j - 1];
		}

		else if (i < strSize && substr[j] != str[i])
		{
			if (j != 0)
			{
				j = pref[j - 1];
			}
			else
			{
				i = i + 1;
			}
		}
	}
}

void prefix(string substr, int substrSize, int* pref)
{
	int len = 0;

	pref[0] = 0;

	int i = 1;
	while (i < substrSize)
	{
		if (substr[i] == substr[len])
		{
			len++;
			pref[i] = len;
			i++;
		}
		else
		{
			if (len != 0)
			{
				len = pref[len - 1];
			}
			else
			{
				pref[i] = 0;
				i++;
			}
		}
	}
}

int main()
{	
	setlocale(LC_ALL, "RU");
	string str;
	string substr;
	cout << "Введите строку: ";
	cin >> str;
	cout << "Введите подстроку: ";
	cin >> substr;
	KMPSearch(substr, str);
	return 0;
}