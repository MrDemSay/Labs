#include <iostream>

using namespace std;

struct Node_2c {
	int data;
	Node_2c *next; //указатель на следующий
	Node_2c *prev; //указатель на предыдущий 
};

struct List_2c {
	Node_2c* head; //указатель на начало
	Node_2c* tail; //указаетль на конец 
};

void init(List_2c& list) {
	list.head = NULL; //инициализация указателя значением NULL
	list.tail = NULL; //
}

Node_2c* create_node(int data = 0) { //параметр по умолчанию 0 (если вызвать функцию без параметров)
	Node_2c* temp;
	temp = new Node_2c;
	temp->data = data;
	temp->next = NULL;
	temp->prev = NULL; // 
	return temp; // на выходе функции, Указатель на область памяти, в которой хранится новый элемент списка
}

void push_back(List_2c& list, int data = 0) {
	if (list.head == NULL) {
		list.head = create_node(data); // проверка. Если список пустой, то указатель head перекидывается сразу на новый элемент
		list.tail = list.head;
	}
	else {
		Node_2c* temp = create_node(data);
		temp->prev = list.tail;
		list.tail->next = temp;
		list.tail = temp;		
	}
}

void push_up(List_2c& list, int data = 0) {
	if (list.head == NULL) {
		list.head = create_node(data);
		list.tail = list.head;
	}
	else {
		Node_2c* temp = create_node(data); // создание элемента
		temp->next = list.head; //установка указателя next
		list.head->prev = temp;
		list.head = temp;  //установка указателя head
	}
}

void push(int p, List_2c& list, int data = 0) {
	if (list.head == NULL) {
		list.head = create_node(data);
		list.tail = list.head;
	}
	else {
		if (p <= 0) 
			push_up(list, data);
		else {
			Node_2c* it = list.head;
			int i = 0;
			while ( (it->next != NULL) && (i < p) ) {
				it = it->next;
				i++;
			}
			if (list.tail == it) 
				push_back(list, data);
			else {
				Node_2c* temp = create_node(data);
				temp->next = it->next;
				temp->prev = it;
				it->next->prev = it;
				it->next = temp;
			}
		}
	}
}

void print(List_2c& list) {
	if (list.head == NULL) 
		cout << "Empty list" << endl;
	else {
		Node_2c* it = list.head;
		while (it != NULL) { //обход списка при помощи указателя
			cout << it->data << " "; //вывод элемента
			it = it->next; //к след элементу
		}
		cout << endl;
	}
}

void reverse_print(List_2c& list) {
	if(list.head == NULL)
		cout << "Empty list" << endl;
	else {
		Node_2c* it = list.tail;
		while (it != NULL) {
			cout << it->data << " "; //вывод элемента
			it = it->prev; //к предыдущему элементу
		}
		cout << endl;
	}
}

void delete_list(List_2c& list) {
	if (list.head != NULL) { // проверка пустой список или нет
		Node_2c* it = list.head, * temp;
		while (it->next != NULL) { // обход списка с помощью it. *temp сохраняет указатель на текущий элемент и удаляет его
			temp = it;
			it = it->next;
			delete temp;
		}
		delete it;
		list.head = NULL;
	}
}


int main()
{
	setlocale(LC_ALL, "ru");

	List_2c list;
	init(list);

	int r, n, p;
	int q = 2; //для цикла

	cout << "Добавление в начало списка - [-1]" << endl;
	cout << "Добавление в конец списка - [1]" << endl;
	cout << "Добавление в любое место списка - [2]" << endl;
	cout << "Завершение работы программы - [0] [0]" << endl;
	cout << endl;
	cout << "Введите номер функции а затем число: ";


	while (q != 0) {
		cin >> n >> r; // номер функции и число
		if (n == 1)
			push_back(list, r);
		else if (n == 2) {
			cout << "Позиция в списке: ";
			cin >> p;
			push(n, list, r);
		}
		else if (n == -1) {
			push_up(list, r);
		}
		else if (n == 0) {
			break;
		}
	}
	cout << "Список: ";
	print(list);

	delete_list(list);

	system("pause");
	return 0;
}

