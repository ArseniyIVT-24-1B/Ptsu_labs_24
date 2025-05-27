#include <iostream>
#include <stack>
#include <vector>

using namespace std;

typedef stack<int> St;
typedef vector<int> Vec;

St make_stack(int n) {
    St s;
    int t;
    for (int i = 0; i < n; i++) {
        cin >> t;
        s.push(t);
    }
    return s;
}


Vec copy_stack_to_vector(St s) {
    Vec v;
    while (!s.empty()) {
        v.push_back(s.top());
        s.pop();
    }
    return v;
}


St copy_vector_to_stack(Vec v) {
    St s;
    for (int i = 0; i < v.size(); i++) {
        s.push(v[i]);
    }
    return s;
}

void print_stack(St s) {
    Vec v = copy_stack_to_vector(s);
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}


int Srednee(St s) {
    Vec v = copy_stack_to_vector(s);
    int sum = 0;
    for (int i = 0; i < v.size(); i++) {
        sum += v[i];
    }
    return sum / v.size();
}


void Add_to_stack(St& s, int el, int pos) {
    Vec v;
    int t;
    int i = 1;
    while (!s.empty()) {
        t = s.top();
        if (i == pos) v.push_back(el);
        v.push_back(t);
        s.pop();
        i++;
    }
    s = copy_vector_to_stack(v);
}


int Max(St s) {
    Vec v = copy_stack_to_vector(s);
    int m = v[0];
    for (int i = 1; i < v.size(); i++) {
        if (v[i] > m) m = v[i];
    }
    return m;
}


void Delete_from_stack(St& s) {
    int m = Max(s);
    Vec v;
    int t;
    while (!s.empty()) {
        t = s.top();
        if (t != m) v.push_back(t);
        s.pop();
    }
    s = copy_vector_to_stack(v);
}


int Min(St s) {
    Vec v = copy_stack_to_vector(s);
    int m = v[0];
    for (int i = 1; i < v.size(); i++) {
        if (v[i] < m) m = v[i];
    }
    return m;
}


void Delenie(St& s) {
    int m = Min(s);
    Vec v;
    int t;
    while (!s.empty()) {
        t = s.top();
        v.push_back(t / m);
        s.pop();
    }
    s = copy_vector_to_stack(v);
}

int main() {
    setlocale(LC_ALL, "Ru");
    try {
        St s;
        int n;
        cout << "Количество элементов ";
        cin >> n;


        s = make_stack(n);
        cout << "Стек: ";
        print_stack(s);


        int avg = Srednee(s);
        cout << "Среднее: " << avg << endl;
        cout << "Позиция для добавления этого среднего ";
        int pos;
        cin >> pos;
        Add_to_stack(s, avg, pos);
        cout << "Стэк: ";
        print_stack(s);


        Delete_from_stack(s);
        cout << "Стэк после удаления максимального: ";
        print_stack(s);


        Delenie(s);
        cout << "Стек после деления на минальное: ";
        print_stack(s);

    }
    catch (int) {
        cout << "Ошибка!";
    }
    return 0;
}