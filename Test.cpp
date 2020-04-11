//#include "stdafx.h"
#include <iostream>
#include <cmath>


using namespace std;

void coordinates(double v0, double t, double rad, double g, double step_time) {
	double x, y;
	int i = 1, q = 0;
	while (q <= t) {
		x = v0 * q * cos(rad);
		y = v0 * q * sin(rad) - g * q * q / 2;
		cout << "Точка" << '[' << i << ']' << ':' << " " << '(' << x << " " <<  ',' << " " << y << ')' << endl;
		q = q + step_time;
		i++;
	}

}


int main() {
	setlocale(LC_ALL, "ru");

	double v0, deg, rad;
	double g = 9.8;
	double h_max, t, s; //s - расстояние
	double step_time;

	cout << "Введите v0 (м/с) и угол в градусах: ";
	cin >> v0 >> deg;
	cout << "Введите шаг по времени в секундах: ";
	cin >> step_time;

	rad = deg * 3.14 / 180; //перевод градусов в радианы

	t = 2 * v0 * sin(rad)  / g;
	s = v0 * v0 * sin(2 * rad) / g;
	h_max = ( v0 * v0 * sin(rad) * sin(rad) ) / (2 * g);

	cout << endl;
	cout << "Расстояние (м) = " << s << endl;
	cout << "Время полёта (сек) = " << t << endl;
	cout << "Максимальная высота (м) = " << h_max << endl;
 
	cout << endl << "Координаты точки с шагом по времени: " << endl;
	coordinates(v0, t, rad, g, step_time);

	cout << endl;

	system("pause");
	return 0;
}

