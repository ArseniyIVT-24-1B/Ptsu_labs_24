#include <iostream>
#include <cstdlib>

using namespace std;


//9. Написать функцию для вычисления суммы элементов квадратной матрицы, которые расположены ниже главной диагонали. 
//С ее помощью найти максимальное значение такой суммы в n матрицах.

void create(int a[5][5]) {
    int range_min, range_max;
    range_min = 10;
    range_max = 99;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            a[i][j] = ((double)rand() / RAND_MAX) * (range_max - range_min) + range_min;
        }
    }
}

void out(int a[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int sum(int a[5][5]) {
    int summ = 0;
    for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (i > j) {
                    summ += a[i][j];
                }
            }
    }
    cout << summ << endl << endl;
    return summ;
}

int main() {
    int MAXSUM = 0;
    int a[5][5];
    int n;
    int tmp;

    cin >> n;


    srand(time(0));
    for (int i = 0; i < n; i++) {

        create(a);
        out(a);
        tmp = sum(a);
        if (tmp > MAXSUM) {
            MAXSUM = tmp;
        }
    
    }

    cout<< "MAXSUM:   " << MAXSUM << endl;

    return 0;
}