#include <iostream>
using namespace std;

void shellSort(int arr[], int n)
{
    for (int h = n / 2; h > 0; h /= 2)
    {
        for (int i = h; i < n; i++)
        {
            int tmp = arr[i];
            int j;
            for (j = i; j >= h && arr[j - h] > tmp; j -= h)
            {
                arr[j] = arr[j - h];
            }
            arr[j] = tmp;
        }
    }
}

int main() 
{
    int a[] = { 1,2,5,4,61,31,0,12,20,500 };
    int n = 10;

    cout << "Unsorted array : ";
    for (size_t i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << "\n";

    shellSort(a, n); 

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    return 0;
}