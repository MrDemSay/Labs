#include <iostream>
#include <cmath>

using namespace std;

void transfer(int T) {
	double t = T - 273;
	cout << "Temper: t" << endl;
}

void func(double w) {
	int q = 0;

	const double R = 8.31;
	const double M = 0.029;
	const double g = 9.81;
	const double p0 = 10000;
	double t = 20;
	double T = t + 273;
	double h = 25;


	while (q <= h) {
		q = q + w;
		double p = p0*exp((-M*g*h) / (R*T));
		double po = (p*M) / (T*R);
		double  t = t - 6;

		cout << "Air temperature" << t << endl;
		cout << "Pressure = " << p << endl;
		cout << "Air density" << po << endl;
	}
}

int main() {
	int w;
	
	cin >> "Enter step by km: " >> w ;
	cout << endl;
	func(w);


	system("pause");
	return 0;
}