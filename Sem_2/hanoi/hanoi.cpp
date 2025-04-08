#include <iostream>
using namespace std;


void visual(int **a,int N) {

    cout << endl;

    for (int i = 0; i < N; i++) {
        for(int j = 0; j < 3; j++){
            if (a[i][j] == 0) {
                for (int k = 0; k < N; k++) {
                    cout << " ";
                }
                cout << "|";
                for (int k = 0; k < N; k++) {
                    cout << " ";
                }

            }
            else {
                for (int k = 0; k < N - a[i][j] + 1; k++) {
                    cout << " ";
                }
                for (int k = 0; k < (a[i][j] * 2) - 1; k++) {
                    cout << "#";
                }
                for (int k = 0; k < N - a[i][j] + 1; k++) {
                    cout << " ";
                }
            }        
        }
        cout << endl;
    }
    cout << endl;
    cout << endl;

}


void moveDisk(int N, int** a, int n, int start, int target) {

    int disk = 0;

    for (int i = 0; i <= N; i++) {
        if (a[i][start - 1] != 0) {
            disk = a[i][start - 1];
            a[i][start - 1] = 0;
            break;
        }
    }

    for (int i = N - 1; i >= 0; i--) {
        if (a[i][target - 1] == 0) {
            a[i][target - 1] = disk;
            break;
        }
    }

    visual(a,N);

}


void hanoi(int N, int** a, int n, int start, int target, int end) {
    
    if (n == 1) {
        cout << "Переместите диск № 1 с " << start << " стержня" << " на " << target << " стержень:" << endl;
        moveDisk(N, a, n, start, target);
        return;
    }
    hanoi(N, a, n - 1, start, end, target);
    cout << "Переместите диск № " << n << " с " << start << " стержня" << " на " << target << " стержень:" << endl;
    moveDisk(N, a, n, start, target);
    hanoi(N, a, n - 1, end, target, start);

}


int main() {
    
    setlocale(LC_ALL, "Ru");
    int n;
    cout << "Введите количество дисков: ";
    cin >> n;

    int N = n;

    int** a = new int* [n];
    for (int i = 0; i < n; ++i) {
        a[i] = new int[3];
    }

    for (int i = 0; i < n; i++) {
        a[i][0] = i + 1;
        a[i][1] = 0;
        a[i][2] = 0;
    }

    moveDisk(N,a,n,0,0);

    hanoi(N, a, n, 1, 2, 3);
    
    
    for (int i = 0; i < n; ++i) {
        delete[] a[i];
    }
    delete[] a;
    return 0;
}
