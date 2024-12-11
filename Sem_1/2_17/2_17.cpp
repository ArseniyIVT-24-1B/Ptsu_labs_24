#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");
    
    long n, facti;
    double x,y;
    y = 0;
    facti = 1;
    cout << "Введите n и x:  " << endl;
    cin >> n >> x;

    for (int i = 0; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            facti = facti * j;
        }

        y += (pow(x, i))/facti;
        facti = 1;
        
    }
        cout << y;    
}