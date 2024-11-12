#include <iostream>
using namespace std;
int main()
{
    float a,b;
    cin >> a;
    if (a < 5) {
        b = a * 3;
       
    }
    else {
        if ((a >= 5) && (a <= 7)) {
            b = a / 10;
            
        }
        else {
            if (a>7) {
               b = a + 3;
               
            }
            else {
                cout << "Error";
            }
        }
    }
    cout << b;
}
