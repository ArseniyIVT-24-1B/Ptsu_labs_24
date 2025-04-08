#include <iostream>
using namespace std;


// Сформировать стек. 
// Удалить из него элемент с заданным номером, добавить элемент с заданным номером

struct Node
{
	int data;
	Node* next;
};

struct Stack
{
	Node* top;
	int size;
	void init()
	{
		top = nullptr;
		size = 0;
	}
};

void push(Stack*& stack, int data)
{
	Node* tmp = new Node;
	tmp->data = data;
	tmp->next = stack->top;
	stack->top = tmp;
	stack->size++;
}

void pop(Stack*& stack)
{
	if (stack->top == nullptr)
	{
		return;
	}
	stack->top = stack->top->next;
	stack->size--;
}
void insert_element(Stack*& stack, int pos, int data)
{
	Stack* tmp = new Stack;
	tmp->init();
	int init_size = stack->size;
	if (pos == 1)
	{
		push(stack, data);
	}
	else
	{
		for (int i = 0; i <= init_size - pos; i++)
		{
			push(tmp, stack->top->data);
			pop(stack);
		}
		push(stack, data);
		init_size = tmp->size;
		for (int i = 0; i < init_size; i++)
		{
			push(stack, tmp->top->data);
			pop(tmp);
		}
	}
	delete tmp;
}

void delete_element(Stack*& stack, int pos)
{
	Stack* tmp = new Stack;
	tmp->init();
	int init_size = stack->size;
	if (pos == 1)
	{
		pop(stack);
	}
	else
	{
		for (int i = 0; i < init_size - pos; i++)
		{
			push(tmp, stack->top->data);
			pop(stack);
		}
		pop(stack);
		init_size = tmp->size;
		for (int i = 0; i < init_size; i++)
		{
			push(stack, tmp->top->data);
			pop(tmp);
		}
	}
	delete tmp;
}


Stack* createStack(int n)
{
	Stack* stack = new Stack;
	stack->init();
	int data;
	for (int i = 0; i < n; i++)
	{
		cin >> data;
		push(stack, data);
	}
	return stack;
}

void printStack(Stack*& stack)
{
	Node* curr = stack->top;
	for (int i = 0; i < stack->size; i++)
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
	cout << "Введите значения элементов: " << endl;
	Stack* stack = createStack(size);
	cout << "Ваш стек: " << endl;
	printStack(stack);
	cout << "Введите элемент который хотите добавить в начало: ";
	cin >> data;
	push(stack, data);
	printStack(stack);
	cout << "Введите элемент и его индекс, чтобы его добавить: ";
	cin >> data;
	cin >> pos;
	insert_element(stack, pos, data);
	printStack(stack);
	cout << "Введите индекc эелемента, который хотите удалить: ";
	cin >> pos;
	delete_element(stack, pos);
	printStack(stack);
	return 0;
}