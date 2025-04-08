#include <iostream>
using namespace std;


// Сформировать очередь. 
// Добавить эелемент в начало, добавить элемент с заданным номером, удалить из него элемент с заданным номером.

struct Node
{
	int data;
	Node* next;
};

struct Queue
{
	Node* front;
	Node* back;
	int size;
	void init()
	{
		front = nullptr;
		back = nullptr;
		size = 0;
	}
};

void push(Queue*& queue, int data)
{
	Node* tmp = new Node;
	tmp->data = data;
	tmp->next = nullptr;
	if (queue->size == 0)
	{
		queue->front = tmp;
		queue->back = tmp;
	}
	else
	{
		queue->back->next = tmp;
		queue->back = tmp;
	}
	queue->size++;
}

void pop(Queue*& queue)
{
	if (queue->size == 0)
	{
		return;
	}
	queue->front = queue->front->next;
	queue->size--;
}
void insert_element(Queue*& queue, int pos, int data)
{
	Queue* tmp = new Queue;
	tmp->init();
	for (int i = 1; i < pos; i++)
	{
		push(tmp, queue->front->data);
		pop(queue);
	}
	push(tmp, data);
	int init_size = queue->size;
	for (int i = 0; i < init_size; i++)
	{
		push(tmp, queue->front->data);
		pop(queue);
	}
	queue = tmp;
}
void delete_element(Queue*& queue, int pos)
{
	Queue* tmp = new Queue;
	tmp->init();
	for (int i = 1; i < pos; i++)
	{
		push(tmp, queue->front->data);
		pop(queue);
	}
	pop(queue);
	int init_size = queue->size;
	for (int i = 0; i < init_size; i++)
	{
		push(tmp, queue->front->data);
		pop(queue);
	}
	queue = tmp;
}



Queue* createQueue(int n)
{
	Queue* queue = new Queue;
	queue->init();
	int data;
	for (int i = 0; i < n; i++)
	{
		cin >> data;
		push(queue, data);
	}
	return queue;
}

void printQueue(Queue*& queue)
{
	Node* curr = new Node;
	curr = queue->front;
	for (int i = 0; i < queue->size; i++)
	{
		cout << curr->data << ' ';
		curr = curr->next;
	}
	cout << endl;
}

int main()
{	
	setlocale(LC_ALL, "RU");
	int size, data, pos, k, element;
	cout << "Введите размер: ";
	cin >> size;
	cout << "Введите значение элементов:" << endl;
	Queue* queue = createQueue(size);
	cout << "ваша очередь:" << endl;
	printQueue(queue);
	cout << "Введите элемент, который вы хотите добавить в начало: ";
	cin >> data;
	push(queue, data);
	printQueue(queue);
	cout << "Значение и позиция элемента, которые хотите добавить: ";
	cin >> data;
	cin >> pos;
	insert_element(queue, pos, data);
	printQueue(queue);
	cout << "Введите номер элемента, который хотите удалить: ";
	cin >> pos;
	delete_element(queue, pos);
	printQueue(queue);
	return 0;
}