#include <iostream>
#include <fstream>
#include <windows.h>
#include <string>

//1) Скопировать из файла F1 в файл F2 все строки, кроме тех, что начинаются на букву А. 
//2) Подсчитать количество символов в первом слове F2.

using namespace std;

int main()
{   
    setlocale(LC_ALL, "RU");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int num;
    string str;
    cout << "Введите количество строк: ";
    cin >> num;
    ofstream fout("F1.txt");
    if (!fout.is_open())
    {
        return 1;
    }

    cin.get();
    for (int i = 0; i < num; i++)
    {
        getline(std::cin, str);
        fout << str << std::endl;
    }
    fout.close();

    ifstream f("F1.txt");
    ofstream fin("F2.txt");

    if (!f.is_open() && !fin.is_open())
    {
        return 1;
    }

    while (getline(f, str))
    {
        if (str[0] != 'A')
        {
            fin << str << std::endl;
        }
    }
    f.close();
    fin.close();

    ifstream f2("F2.txt");
    int syms = 0;
    if (!f2.is_open())
    {
        return 1;
    }
    getline(f2, str);
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] != ' ')
        {
            syms++;
        }
        else
        {
            break;
        }
    }
    f2.clear();
    f2.seekg(0);

    while (f2.peek() != EOF)
    {
        getline(f2, str);
        cout << str << '\n';
    }

    f2.close();
    cout << "Количество символов во втором файле в первом слове: " << syms << endl;
    return 0;
}