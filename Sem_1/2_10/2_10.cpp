#include <iostream>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");

    int n, nummax;

    cout << "введните количество чисел в последовательности:  " << endl;
    cin >> n;
    cout << "введите последовательность:  " << endl;
    cin << nummax;
    for (int i = 0; i < n; i++) {
        cin >> num;
        if (num > nummax) {
            nummax = num;
        }
    }
    cout << "вот наибольшее число в этой последовательности: " << endl;
    cout << nummax;

    return 0;
}