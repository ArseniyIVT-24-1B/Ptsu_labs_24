#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");
    
    bool flag, flag2;
    flag = false;
    flag2 = false;
    int n,n2;

    cout << "Введите последовательность:" << endl;
    cin >> n;
    n2 = n;
    while (!flag) {
        cin >> n;
        if (n == 0) {
            flag = true;
        }
        else if (n <= n2) {
            flag2 = true;
        }
        n2 = n;
    }
    if (flag2) { cout << "Числа не упородоченны по возрастанию"; }
    else if (!flag2) { cout << "Числа упорядоченны по возрастанию"; }

}