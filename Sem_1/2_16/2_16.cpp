#include <iostream>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");
    
    int n,j,S;
    S = 0;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        if (i % 2 == 1) { j = -i; }
        else { j = i; }
        S += j;
    }
    cout << S;
}