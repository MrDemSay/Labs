#include <iostream>
#include <cmath>
#include <fstream>



using namespace std;

void func(int w) {
	int q = 0;
	int i = 0;

	const double R = 8.31;
	const double M = 0.029;
	const double g = 9.81;
	const double p0 = 100000;
	double t = 20;
	double T = 0;
	double h = 25;
	double r = h;

	ofstream fout;
	fout.open("D:\data.txt");

	while (q < r) {
		q = q + w;


		t = t - 6;
		T = t + 273;
		h = h - w;

		
		double p = p0 * exp((-M * g * h) / (R * T));
		double po = (p * M) / (T * R);

		

		i = i + 1; //counter for index
		fout << "[" << i << "]" << " -------------" << endl; //index
		fout << "Air temperature (t) = " << t << endl;
		fout << "Pressure (p) = " << p << endl;
		fout << "Air density (po) = " << po << endl;
		fout << "-------------------" << endl;
		fout << endl;

		
	}

	fout << "Calculations completed";
	fout.close();
}

int main() {
	int w = 1;

	cout << "Calculations completed" << endl;
	func(w);

	

	system("pause");
	return 0;
}
