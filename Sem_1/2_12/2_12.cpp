#include <iostream>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");

    int N, n, min, max;

    cout << "введите количество чисел послдовательности: " << endl;

    cin >> n;

    cout << "введите последовательность: " << endl;
    
    cin >> N;

    max = N;
    min = N;

    for (int i = 1; i <= n - 1; i++) {
        cin >> N;
        
        if (N < min) { min = N; }
        if (N > max) { max = N; }

    }
    cout << "сумма максимального и минимального элемента последоваткльности: " << endl;
    cout << max + min;
}