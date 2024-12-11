#include <iostream>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");
    
    int N,NUM;
    cout << "Введите натуральное число:" << endl;
    cin >> N;

    cout << "Вот перевёрнутое число:   ";
    while (N > 0) {
        NUM = N % 10;
        N = N / 10;
        cout << NUM;
    }
}