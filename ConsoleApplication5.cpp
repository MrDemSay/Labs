//#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

void work_text(vector<string>& text) {
	for (int i = 0; i < text.size(); i++) {
		string text_word;

		for (int j = 0; j < text[i].size(); j++) {
			if ((text[i][j] == ' ') || (text[i][j] == ',') || (text[i][j] == '.') || (text[i][j] == '!') || (text[i][j] == '?') || (text[i][j] == '-') || (text[i][j] == '\n')) {
				cout << text_word.c_str() << " ";
				text_word.clear();
			}
			text_word.push_back(text[i][j]);
		}
		cout << text_word.c_str() << " "; 
	}
}

void work_dictionary(vector<string>& dictionary) {
	for (int i = 0; i < dictionary.size(); i++) {
		string word, sinonim;

		word.clear();
		sinonim.clear();

		int j = 0;
		while (dictionary[i][j] != '-') // получение слова из словаря
			word.push_back(dictionary[i][j++]);
		j++; // переход на один символ ('-')

		while (j < dictionary[i].size()) // получение синонима слова
			sinonim.push_back(dictionary[i][j++]);

		cout << word << " - " << sinonim << endl; // для проверки
	}

}

void compare(string& word, string& sinonim, string& text_word) {
	if (word == text_word) {
		text_word = sinonim;
	}
}

int main() {
	setlocale(LC_ALL, "ru");

	ifstream fin; // входной поток для текста
	ifstream dic; // входной поток для словаря 
	ofstream fout; // выходной поток
	string text_line, dic_line; // строка/информация из файла
	vector<string> text, dictionary, word_text, word_dictionary, word_sinonim;

	fin.open("list1.txt"); // открыт текст на чтение
	dic.open("list2.txt"); // открыт словрь на чтение
	fout.open("list1.txt", ofstream::app); // открыт текст на запись и замену слов


	// работа с текстом -----------------------------------------------------------
	if (fin.is_open()) {  
		while (!fin.eof()) {
			//text_line = ""; //для очистки строки
			getline(fin, text_line);
			text.push_back(text_line);
		}
		
	} 
	else {
		cout << "Ошибка. Файл не открыт" << endl;
	}


	// работа со словарём ---------------------------------------------------------
	if (dic.is_open()) { 
		while (!dic.eof()) {
			//dic_line = ""; //для очистки строки
			getline(dic, dic_line);
			dictionary.push_back(dic_line);
		}
	}
	else {
		cout << "Ошибка. Файл не открыт";
	}

	string text_word = "";

	cout << "Dictionary: ";
	work_dictionary(dictionary);
	cout << "Text: ";
	work_text(text);

	fin.close();
	dic.close();
	fout.close();

	cout << "Copying completed" << endl;

	system("pause");
	return 0;
}

//dic_line  - строка из словаря
//text_line - строка из текста
//veсtors: text and dictionary - массивы символов (тексты из файлов)

