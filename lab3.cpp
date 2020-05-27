#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;


void dictionary(string namefile);

void scan_text() {}; 


int main() {
	setlocale(LC_ALL, "Russian");
	string dic_file;
	vector<string> t;

	dic_file = "dictionary.txt";

	dictionary(dic_file);

	system("pause");
	return 0;
}

void dictionary(string namefile) {
	ifstream in;
	string dic_line, word, sinonim;
	in.open(namefile.c_str());
	if (in.is_open()) {
		while (!in.eof()) {
			getline(in, dic_line);
			int i = 0;
			while (dic_line[i] != '-') {
				word.push_back(dic_line[i]);
			}
			i++;
			while (dic_line[i] != ';') {
				sinonim.push_back(dic_line[i]);
			}
			cout << word << "0" << sinonim << endl;
		}
	}
	else {
		cout << "Error. File close." << endl;
	}

	in.close();
}

void scan_text(string namefile, vector<string>& textW) {
	ifstream in;
	in.open(namefile.c_str());
	string text_line;
	if (in.is_open()) {
		getline(in, text_line);
		for (int i = 0; i < text_line.size(); i++) {
			if (text_line[i] != ' ' || text_line[i] != ',' || text_line[i] != '.' || text_line[i] != '!' || text_line[i] != '?' || text_line[i] != '-' || text_line[i] != '\n') {
				textW.push_back(text_line);
				i++;
			}
		}

	}
	else {
		cout << "Error. File close." << endl;
	}
}
