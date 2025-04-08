#include <iostream>
using namespace std;

// Сформировать двунаправленный список. 
// Удалить из него элемент с заданным номером, добавить элемент с заданным номером;

struct ListElem
{
    int data;
    ListElem* next;
    ListElem* prev;
};

ListElem* createList(int n)
{
    ListElem* start;
    ListElem* prev, * curr;
    start = new ListElem;
    cin >> start->data;
    start->next = nullptr;
    start->prev = nullptr;
    prev = start;
    for (int i = 0; i < n - 1; i++)
    {
        curr = new ListElem;
        cin >> curr->data;
        curr->next = nullptr;
        curr->prev = prev;
        prev->next = curr;
        prev = curr;
    }
    return start;
}

void insert_element(ListElem*& start, int pos, int k, int& size)
{
    size++;
    ListElem* first = start;
    ListElem* last;
    for (int i = 1; i < pos - 1; i++)
    {
        first = first->next;
    }
    last = first->next;

    ListElem* new_element = new ListElem;
    cout << "Значение: ";
    cin >> new_element->data;
    if (pos == 1)
    {
        new_element->prev = nullptr;
        start->prev = new_element;
        new_element->next = start;
        start = new_element;
    }
    else
    {
        new_element->prev = first;
        new_element->next = last;
        if (last != nullptr)
        {
            last->prev = new_element;
        }
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
    last = first->next;
    if (pos == 1)
    {
        start = start->next;
        start->prev = nullptr;
    }
    else
    {
        first->next = last->next;
        if (last->next != nullptr)
        {
            last->next->prev = first;
        }
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
    cout << "Введите элементы: ";
    ListElem* list = createList(size);
    cout << "Ваш список: " << endl;
    printList(list, size);
    cout << "Введите номер элемента, который хотите добавить: ";
    cin >> pos;
    insert_element(list, pos, 1, size);
    printList(list, size);
    cout << "Введи номер элемнта, который хотите удалить: ";
    cin >> pos;
    delete_element(list, pos, 1, size);
    printList(list, size);
    deleteList(list);
    return 0;
}