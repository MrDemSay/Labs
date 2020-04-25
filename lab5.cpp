#include <iostream>

using namespace std;

struct Node_2c {
	int data;
	Node_2c* next; 
	Node_2c* prev; 
};


struct List_2c {
	Node_2c* head; //указатель на начало
	Node_2c* tail; //указаетль на конец 
};


void init(List_2c& list) {
	list.head = NULL; 
	list.tail = NULL; 
}


Node_2c* create_node(int data = 0) { 
	Node_2c* temp;
	temp = new Node_2c;
	temp->data = data;
	temp->next = NULL;
	temp->prev = NULL; 
	return temp; // на выходе функции, Указатель на область памяти
}


void push_up(List_2c& list, int data = 0) {
	if (list.head == NULL) {
		list.head = create_node(data);
		list.tail = list.head;
	}
	else {
		Node_2c* temp = create_node(data); 
		temp->next = list.head; 
		list.head->prev = temp;
		list.head = temp;  
	}
}


void push_back(List_2c& list, int data = 0) {
	if (list.head == NULL) {
		list.head = create_node(data);
		list.tail = list.head;
	}
	else {
		Node_2c* temp = create_node(data);
		temp->prev = list.tail;
		list.tail->next = temp;
		list.tail = temp;
	}
}


void push_elem(List_2c& list, int data = 0) {
	if (list.head == NULL) {
		list.head = create_node(data);
		list.tail = list.head;
	}
	else {
		Node_2c* it = list.head;
		Node_2c* en = list.tail;
		if (it->data <= data)
			push_up(list, data);

		else if (en->data >= data) 
			push_back(list, data);

		else {
			Node_2c* it = list.head;
			while ((it != NULL) && (it->data > data)) {
				it = it->next;
			}

			Node_2c* temp = create_node(data);
			temp->next = it;
			temp->prev = it->prev;
			it->prev->next = temp;
			it->prev = temp;
		}
	}
}


void print(List_2c& list) {
	if (list.head == NULL)
		cout << "Empty list" << endl;
	else {
		Node_2c* it = list.head;
		while (it != NULL) { 
			cout << it->data << " ";
			it = it->next; 
		}
		cout << endl;
	}
}


void find_copy(List_2c& list, int data) {
	int e = 0; //счётчик
	if (list.head != NULL) {
		Node_2c* it = list.head;
		while (it != NULL) { 
			if (it->data == data)
				e++;
			it = it->next; 
		}
		cout << "---------------------" << endl;
		cout << "Numbers copy: " << e << endl;
		cout << "---------------------" << endl;
	}
}


void delete_last_elem(List_2c& list) {
	if (list.head != NULL) { // проверка пустой список или нет
		Node_2c* it = list.head, * temp;
		while (it->next->next != NULL) { // обход списка с помощью it. *temp сохраняет указатель на текущий элемент и удаляет его
			temp = it;
			it = it->next;
		}
		delete it->next;
		it->next = NULL;
		
	}
}


void delete_list(List_2c& list) {
	if (list.head != NULL) { 
		Node_2c* it = list.head, * temp;
		while (it->next != NULL) { // обход списка с помощью it. *temp сохраняет указатель на текущий элемент и удаляет его
			it = it->next;
			temp = it;
		}
		temp = NULL;
		delete it;
	}
}


int main()
{
	setlocale(LC_ALL, "ru");

	List_2c list;
	init(list);

	int r, n;
	int q = 2; //для цикла

	cout << "Добавление в список - [1]" << endl;
	cout << "Поиск копии - [2]" << endl;
	cout << "Удаление последнего элемента списка - [3]" << endl;
	cout << "Завершение работы программы - [0]" << endl;
	cout << endl;
	cout << "----------------" << endl;
	cout << "Введите номер функции а затем число: " << endl;
	cout << "----------------" << endl;


	while (q != 0) {
		cout << "Number function: ";
		cin >> n; // номер функции и число
		if (n == 1) {
			cout << "Number: ";
			cin >> r;
			push_elem(list, r);
		}
		else if (n == 2) {
			cout << "Find copy of number: ";
			cin >> r;
			find_copy(list, r);
		}
		else if (n == 3) {
			delete_last_elem(list);
		}
		else if (n == 0) {
			break;
		}
	}
	cout << "-----------------------------------------" << endl;
	cout << "Список: ";
	print(list);
	cout << "-----------------------------------------" << endl;


	delete_list(list);

	system("pause");
	return 0;
}
