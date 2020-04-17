#include <iostream>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

struct students {
	string name;
	double midMark;
};

void print(students& stud, vector<students>& arr) { //вывод информации о студенте и его оценках
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i].name << " " << arr[i].midMark << endl;
	}
}
void sort(vector<students>& arr) { //сортировка рейтинга вставками 

	int position = 0;
	int vector_size = arr.size();
	for (int i = 1; i < vector_size; i++)
		for (int j = i; j > 0 && arr[j - 1].midMark > arr[j].midMark; j--) { // пока j>0 и элемент j-1 > j, arr - массив int
			swap(arr[j - 1].midMark, arr[j].midMark); // меняем местами элементы j и j-1
			swap(arr[j - 1].name, arr[j].name); // меняем местами элементы j и j-1
		}

	cout << "Рейтинг: " << endl; //вывод рейтинга студентов
	for (int i = vector_size - 1; i >= 0; i--) {
		position++;
		cout << '[' << position << ']' << ':' << " " << arr[i].name << " " << arr[i].midMark << endl;
	}
}



int main() {
	setlocale(LC_ALL, "ru");

	double midMark, r;
	students stud;
	int i1, i2, i3, i4, i5; //оценки
	string name;
	int q = 1; //для цикла

	vector<students> arr; // массив структур

	while (q != 0) {
		cout << "[1] - добавить элемент. [0] - завершить" << endl;

		cin >> r;

		if (r == 1) {
			cout << "Введите имя студента, его оценки: ";
			cin >> name >> i1 >> i2 >> i3 >> i4 >> i5;
			midMark = (i1 + i2 + i3 + i4 + i5) / 5.0;
			
			students info = { name, midMark };
			arr.push_back(info); //добавляем структуру в массив
		}
		else if (r == 0) {
			break;
		}
	}

	cout << "-------------------------------------" << endl;
	cout << "Список: " << endl;

	print(stud, arr);

	cout << "-------------------------------------" << endl;
	sort(arr); //рейтинг студентов


	system("pause");
	return 0;
}