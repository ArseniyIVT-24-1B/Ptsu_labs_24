#include<iostream>
#include<cmath>
using namespace std;
int main()
{	
	int n,edge;

	cin >> n;

	edge = (n/sqrt(2)) - 1;
	
	cout << edge << endl;

	for (int i = 0; i < edge; i++) {

		for (int j = edge; j > i; j--) {
			cout << "  ";
		}

		if (i == 0) {		
			

				for (int j = 0; j < n; j++) {

				cout << "* ";

				}

			

		}



		else {
			
			cout << "* ";

			for(int j = 0; j < n - 2; j++){
			
				cout << "  ";
			
			}

			cout << "* ";

			for (int j = edge - i; j < edge-1; j++) {

				cout << "  ";

			}

			cout << "* ";
			
		}

		cout << endl;

	}

	for (int i = 0; i < n; i++) {
	
		cout << "* ";

	}

	for (int i = 0; i < edge - 1; i++) {

		cout << "  ";

	}
	
	cout << "* " << endl;
	
	for (int i = 0; i < n - 2; i++) {

		cout << "* ";

		for (int j = 0; j < n - 2; j++) {

			cout << "  ";

		}

		cout << "* ";

		if (n - i - 3 < edge ) {

			for (int j = i - n + edge; j < edge - 3; j++) {

				cout << "  ";

			}


		}
		else {
			for (int j = 0; j < edge - 1; j++) {

				cout << "  ";

			}
		}
		cout << "* ";

		cout << endl;

	}
	
	for (int i = 0; i < n; i++) {

		cout << "* ";

	}
	return 0;
}