#include <iostream>
using namespace std;

// Сформировать однонаправленный список. 
// Удалить из него элемент с заданным номером, добавить элемент с заданным номером;

struct ListElem
{
    int data;
    ListElem* next;
};

ListElem* createList(int n)
{
    ListElem* start;
    ListElem* prev, * curr;
    start = new ListElem;
    cin >> start->data;
    start->next = nullptr;
    prev = start;
    for (int i = 0; i < n - 1; i++)
    {
        curr = new ListElem;
        cin >> curr->data;
        curr->next = nullptr;
        prev->next = curr;
        prev = curr;
    }
    return start;
}

void insert_element(ListElem*& start, int pos, int k, int& size)
{
    size++;
    ListElem* first = start;
    for (int i = 1; i < pos - 1; i++)
    {
        first = first->next;
    }

    ListElem* new_element = new ListElem;
    cout << "Введите значение: ";
    cin >> new_element->data;

    if (pos == 1)
    {
        new_element->next = first;
        start = new_element;
    }
    else
    {
        new_element->next = first->next;
        first->next = new_element;
    }
}


void delete_element(ListElem*& start, int pos, int k, int& size)
{
    size--;
    ListElem* first = start;
    ListElem* last;
    for (int i = 1; i < pos - 1; i++)
    {
        first = first->next;
    }
    if (pos == 1)
    {
        start = first->next;
        first->next = start;
    }
    else
    {
        last = first->next->next;
        first->next = last;
    }
}

void printList(ListElem* start, int n)
{
    ListElem* curr = start;
    for (int i = 0; i < n; i++)
    {
        cout << curr->data << ' ';
        curr = curr->next;
    }
    cout << endl;
}

void deleteList(ListElem* list)
{
    delete list;
}

int main()
{   
    setlocale(LC_ALL, "Ru");
    int size, pos, k, element;
    cout << "Введите размер: ";
    cin >> size;
    cout << "Введите значения элемнтов: ";
    ListElem* list = createList(size);
    cout << "Ваш лист:" << endl;
    printList(list, size);
    cout << "Введите номер элемента, который хотите добавить: ";
    cin >> pos;
    insert_element(list, pos, 1, size);
    printList(list, size);
    cout << "Введите элемент, котоый хотите удалить: ";
    cin >> pos;
    delete_element(list, pos, 1, size);
    printList(list, size);
    deleteList(list);
    return 0;
}