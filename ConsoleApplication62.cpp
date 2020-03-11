#include "stdafx.h"
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

double coord(double deg, double v0) {
	double v, h, s, t, x ,y;
	const float g = 9.8;
	const double x0 = 0, y0 = 0;
	x = x0 + v0*t*cos(deg);
	y = y0 + v0*t*sin(deg) - g*(t*t)/2;
	while (h >= 0) {

	}
	return 0;
}

int main()
{
	double deg, v, h_max, v0, s, t;
	const float g = 9.8;
	cout << "Deg: ";
	cin >> deg;
	cout << "v0";
	cin >> v0;
	cout << "v";
	cin >> v;

	t = v0*sin(deg) / g;
	s = v0*t*cos(deg);
	
	system("pause");
    return 0;
}

//нач скорость, угол