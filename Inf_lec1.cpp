#include <iostream>

using namespace std;

struct Node { // описывает сам узел
	int data; // поле с данными которые необходимо хранить
	Node* next; //указатель на следующий элемент
};

struct List { // хранит указатель на голову списка
	Node* head; // указатель на голову списка
};

void init(List& list) {
	list.head = NULL; //инициализация указателя значением NULL
}

Node* create_node(int data = 0) { //параметр по умолчанию 0 (если вызвать функцию без параметров)
	Node* temp; 
	temp = new Node;
	temp->data = data;
	temp->next = NULL;
	return temp; // на выходе функции, Указатель на область памяти, в которой хранится новый элемент списка
}

void push_back(List& list, int data = 0) {
	if (list.head == NULL) {
		list.head = create_node(data); // проверка. Если список пустой, то указатель head перекидывается сразу на новый элемент
	}
	else {
		Node* temp = create_node(data);
		Node* it = list.head;
		while (it->next != NULL) //обход списка. Последним считается элемент = NULL.  
			it = it->next; // с помощью указателя it происходит движение по списку вперёд
		it->next = temp;
	}
}

void push_up(List& list, int data = 0) {
	if (list.head == NULL) {
		list.head = create_node(data);
	}
	else {
		Node* temp = create_node(data); // создание элемента
		temp->next = list.head; //установка указателя next
		list.head = temp;  //установка указателя head
	}
}

void print(List& list) {
	if (list.head == NULL) {
		cout << "Empty list" << endl;
	}
	else {
		Node* it = list.head; 
		while (it != NULL) { //обход списка при помощи указателя
			cout << it->data << " "; //вывод элемента
			it = it->next; //шаг к след элементу
		}
		cout << endl;
	}
}

void delete_list(List& list) {
	if (list.head != NULL) { // проверка пустой список или нет
		Node* it = list.head, *temp; 
		while (it->next != NULL) { // обход списка с помощью it. *temp сохраняет указатель на текущий элемент и удаляет его
			temp = it;
			it = it->next;
			delete temp;
		}
		delete it;
		list.head = NULL;
	}
}


int main() {
	setlocale(LC_ALL, "ru");

	List list;
	init(list);
	int r, n;
	int q = 2; //для цикла

	cout << "Добавление в конец списка - 1" << endl;
	cout << "Добавление в начало списка - 2" << endl;
	cout << "Завершение работы программы - 0 0" << endl;
	cout << endl;
	cout << "Введите число и номер функции: ";


	while (q != 0) {
		cin >> r;
		cin >> n;//число и номер функции
		if (n == 1)
			push_back(list, r);
		else if (n == 2) {
			push_up(list, r);
		}
		else if (r == 0) {
			break;
		}
	}
	cout << "Список: ";
	print(list);
	
	delete_list(list);

	system("pause");
	return 0;
}

