#include <cstdlib>
#include <iostream> 
using namespace std; 
int main() {
	const int n = 7; 
	int arr[n]; 
	int tmp, range_min, range_max; range_min = 2; 
	range_max = 412; 
	for (int i = 0; i < n; i++) { 
		arr[i] = ((double)rand() / RAND_MAX) * (range_max - range_min) + range_min; 
		cout << arr[i] << " "; 
	} 
	cout << endl; 
	for (int i = 0; i < n-1; i++) { 
		for (int j = 0; j < n-1-i; j++) { 
			if (arr[j] > arr[j+1]) { 
				tmp = arr[j]; 
				arr[j] = arr[j+1]; arr[j+1] = tmp; 
			} 
		} 
	} 
	for (int i = 0; i < n; i++) { 
		cout << arr[i] << " "; 
	} 
	cout << endl; 
	return 0; 
}