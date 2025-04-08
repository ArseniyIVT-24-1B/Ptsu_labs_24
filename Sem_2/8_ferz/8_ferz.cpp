#include <iostream>
#include <Windows.h>

using namespace std;

int dosk[8][8]; //создание доски

void prev() //функция, отвечающия за вывод в консоль
{
	cout << "---------------" << endl << endl;
	for (int i = 0; i < 8; i++) 
	{
		for (int j = 0; j < 8; j++) 
		{
			if (dosk[i][j] == -1) 
			{
				HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(handle,FOREGROUND_GREEN);
				cout << "Q ";
			}
			else 
			{
				HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(handle, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
				cout << "# ";
			}
		}
		cout << endl;
	}
	cout << endl;
}

void deleteFERS(int i, int j) // функция для удаления ферзей
{
	for (int k = 0; k < 8; k++) 
	{
		--dosk[i][k];
		--dosk[k][j];
		int diag;
		diag = j - i + k;
		if (diag >= 0)
		{
			if (diag < 8)
			{
				--dosk[k][diag];
			}
		}
		diag = j + i - k;
		if (diag >= 0)
		{
			if (diag < 8)
			{
				--dosk[k][diag];
			}
		}
	}
	dosk[i][j] = 0;
	prev();
}

void setFERS(int i, int j) // функция для установки ферзей
{
	for (int k = 0; k < 8; k++) 
	{
		++dosk[i][k];
		++dosk[k][j];
		int diag;
		diag = j - i + k;
		if (diag >= 0)
		{
			if (diag < 8)
			{
				++dosk[k][diag];
			}
		}
		diag = j + i - k;
		if (diag >= 0)
		{
			if (diag < 8)
			{
				++dosk[k][diag];
			}
		}
	}
	dosk[i][j] = -1;
	prev();
}

bool FERS(int i) // главная функция для решения задачи
{

	bool result = false;

	for (int j = 0; j < 8; j++) 
	{
		if(dosk[i][j] == 0)
		{
			setFERS(i, j);
			if (i == 7) 
			{
			result = true;
			}
			else {
				if (!(result = FERS(i + 1)))
				{
					deleteFERS(i, j);
				}
			}
		}
		if (result)
		{
			break;
		}
	}
	return result;
}

int main()
{	
	FERS(0);
	return 0;
}
