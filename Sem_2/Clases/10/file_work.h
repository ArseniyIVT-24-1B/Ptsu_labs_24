#include "Time.h"

int make_file(const char* filename) {
    fstream file(filename, ios::out | ios::trunc);
    if (!file) return -1;

    int n;
    cout << "Enter number of entries: ";
    cin >> n;

    Time t;
    for (int i = 0; i < n; ++i) {
        cout << "Entry " << i + 1 << " (format M:SS): ";
        cin >> t;
        file << t;
    }

    file.close();
    return n;
}

int print_file(const char* filename) {
    fstream file(filename, ios::in);
    if (!file) return -1;

    Time t;
    int count = 0;
    while (file >> t) {
        cout << t << endl;
        count++;
    }

    file.close();
    return count;
}

int delete_by_value(const char* filename, Time value) {
    fstream temp("temp.txt", ios::out);
    fstream file(filename, ios::in);
    if (!file) return -1;

    Time t;
    int deleted = 0;
    while (file >> t) {
        if (t == value) {
            deleted++;
        }
        else {
            temp << t;
        }
    }

    file.close();
    temp.close();
    remove(filename);
    rename("temp.txt", filename);
    return deleted;
}

int add_after(const char* filename, int pos, int k) {
    fstream file(filename, ios::in);
    if (!file) return -1;

    fstream temp("temp.txt", ios::out);
    Time t;
    int current = 0;
    while (file >> t) {
        temp << t;
        current++;
        if (current == pos) {
            for (int i = 0; i < k; ++i) {
                Time new_t;
                cout << "Enter new entry " << i + 1 << " (format M:SS): ";
                cin >> new_t;
                temp << new_t;
            }
        }
    }

    if (current < pos) {
        for (int i = 0; i < k; ++i) {
            Time new_t;
            cout << "Enter new entry " << i + 1 << " (format M:SS): ";
            cin >> new_t;
            temp << new_t;
        }
    }

    file.close();
    temp.close();
    remove(filename);
    rename("temp.txt", filename);
    return k;
}

int increase_by_value(const char* filename, Time value) {
    fstream temp("temp.txt", ios::out);
    fstream file(filename, ios::in);
    if (!file) return -1;

    Time t;
    Time increment(1, 30);
    int updated = 0;
    while (file >> t) {
        if (t == value) {
            temp << (t + increment);
            updated++;
        }
        else {
            temp << t;
        }
    }

    file.close();
    temp.close();
    remove(filename);
    rename("temp.txt", filename);
    return updated;
}