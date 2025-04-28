#include "Time.h"
#include "file_work.h"
#include <iostream>
using namespace std;

int main() {
    int choice;
    char filename[50];
    do {
        cout << "\nMenu:\n"
            << "1. Create file\n"
            << "2. Display file\n"
            << "3. Delete entries by value\n"
            << "4. Add K entries after position\n"
            << "5. Increase entries by value\n"
            << "0. Exit\n"
            << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            cout << "Enter filename: ";
            cin >> filename;
            int result = make_file(filename);
            if (result < 0) cout << "Error creating file!\n";
            break;
        }
        case 2: {
            cout << "Enter filename: ";
            cin >> filename;
            int result = print_file(filename);
            if (result < 0) cout << "Error reading file!\n";
            else cout << "Total entries: " << result << endl;
            break;
        }
        case 3: {
            cout << "Enter filename: ";
            cin >> filename;
            Time value;
            cout << "Enter value to delete (format M:SS): ";
            cin >> value;
            int result = delete_by_value(filename, value);
            if (result < 0) cout << "Error!\n";
            else cout << "Deleted entries: " << result << endl;
            break;
        }
        case 4: {
            cout << "Enter filename: ";
            cin >> filename;
            int pos, k;
            cout << "Enter position and K: ";
            cin >> pos >> k;
            int result = add_after(filename, pos, k);
            if (result < 0) cout << "Error!\n";
            else cout << "Added entries: " << result << endl;
            break;
        }
        case 5: {
            cout << "Enter filename: ";
            cin >> filename;
            Time value;
            cout << "Enter value to increase (format M:SS): ";
            cin >> value;
            int result = increase_by_value(filename, value);
            if (result < 0) cout << "Error!\n";
            else cout << "Updated entries: " << result << endl;
            break;
        }
        case 0:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 0);

    return 0;
}