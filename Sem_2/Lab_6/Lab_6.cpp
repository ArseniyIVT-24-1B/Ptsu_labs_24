#include <iostream>
#include <string>
using namespace std;

// 9. Преобразовать строку так, чтобы все слова в ней стали идентификаторами, слова состоящие только из цифр - удалить.

string transform(string stroka)
{
    string word;

    int i = 0;

    while (i < stroka.length()) {
        
        bool num;
        
        bool is_digit_only = true;
        int start = i;

        while (i < stroka.length() && stroka[i] == ' ') {
            i++;
        }
        
        while (i < stroka.length() && stroka[i] != ' ') {
            if (stroka[i] < '0' || stroka[i] > '9') {
                is_digit_only = false;
            }
            i++;
        }

        if (is_digit_only) {
            continue;
        }

        for (int j = start; j < i; j++) {
            if ((stroka[j] >= 'a' && stroka[j] <= 'z') ||
                (stroka[j] >= 'A' && stroka[j] <= 'Z') ||
                (stroka[j] >= '0' && stroka[j] <= '9') ||
                (stroka[j] == '_') || (stroka[j] == ' ')) {
                
                word += stroka[j];
            }
            else {
                word += '_';
            }
        }
    }
    return word;
}

int main() 
{   
    setlocale(LC_ALL, "ru");
    string stroka;
    cout << "Введите слово: ";
    getline(cin, stroka);

    string result = transform(stroka);
    cout << "Результат: " << result << endl;
    return 0;
}
