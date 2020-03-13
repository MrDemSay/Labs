#include "stdafx.h"
#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

void compare(vector<string>& text, map <string, string>& word_sin, ofstream& out) {
	string line;
	word_sin = { }; //map

	for (int i = 0; i <= text.size(); i++) {
		for (int j = 0; j <= text[i].size(); j++) {
			if ((text[i][j] == ' ') || (text[i][j] == ',') || (text[i][j] == '\n')) {
				map <string, string>::iterator it = word_sin.find(line); //проверить в словарь
				if (it != word_sin.end()) {
					out << it->second;
				} else
					out << line;
				out << text[i][j];
				line.clear();
			} else
				line.push_back(text[i][j]);
		}
	}
}

void dic(vector<string>& dictionary, map <string, string>& word_sin) {
	string word, sin;

	for (int i = 0; i <= dictionary.size(); i++) {
		word.clear();
		sin.clear();
		int j = 0;
		while (dictionary[i][j] != '-')
			word.push_back(dictionary[i][j++]);
		j++;

		while (dictionary[i][j] != '\n')
			sin.push_back(dictionary[i][j++]);

		word_sin.insert({ word, sin });

	}
}

int main() {

	//Start
	string line;
	vector<string> text;
	vector<string> dictionary;
	//Открытие файла текста
	ofstream inop;
	inop.open("list1.txt");
	if (inop.is_open()) {
		while (!inop.eof()) {
			//getline(inop, line);
			text.push_back(line); //Копирование в вектор text
		}
		inop.close();
		line.clear();

	}

	//Открытие Файла словаря
	ifstream fout;
	fout.open("list2.txt");
	if (fout.is_open()) {
		while (!fout.eof()) {
			getline(fout, line);
			dictionary.push_back(line); //Копирование в вектор dictionary
		}
		fout.close();
		fout.clear();
	}
	map <string, string> word_sin;

	dic(dictionary, word_sin);
	compare(text, word_sin, fout);

	system("pause");
	return 0;
}
