/*
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
const double a = 0;
const double b = 1;
const double h = 0.1;
const double yf = 0;
const double zf = -1;
double calculate_y(double t, double y, double z)
{
	double k1 = y*(-4) - z * 2 + cos(t) + sin(t) * 4;
	double L1 = y * 3 + z - sin(t) * 3;
	double k2 = (y + h / 2 * k1)*(-4) - (z + h / 2 * L1) * 2 + cos(t + h / 2) + sin(t + h / 2) * 4;
	double L2 = (y + h / 2 * k1) * 3 + (z + h / 2 * L1) - sin(t + h / 2) * 3;
	double k3 = (y + h / 2 * k2)*(-4) - (z + h / 2 * L2) * 2 + cos(t + h / 2) + sin(t + h / 2) * 4;
	double L3 = (y + h / 2 * k2) * 3 + (z + h / 2 * L2) - sin(t + h / 2) * 3;
	double k4 = (y + h*k3)*(-4) - (z + h * L3) * 2 + cos(t + h) + sin(t + h) * 4;
	double L4 = (y + h*k3) * 3 + (z + h*L3) - sin(t + h) * 3;
	return (y + h / 6 * (k1 + k2 * 2 + k3 * 2 + k4));
}


double calculate_z(double t, double y, double z)
{
	double k1 = y*(-4) - z * 2 + cos(t) + sin(t) * 4;
	double L1 = y * 3 + z - sin(t) * 3;
	double k2 = (y + h / 2 * k1)*(-4) - (z + h / 2 * L1) * 2 + cos(t + h / 2) + sin(t + h / 2) * 4;
	double L2 = (y + h / 2 * k1) * 3 + (z + h / 2 * L1) - sin(t + h / 2) * 3;
	double k3 = (y + h / 2 * k2)*(-4) - (z + h / 2 * L2) * 2 + cos(t + h / 2) + sin(t + h / 2) * 4;
	double L3 = (y + h / 2 * k2) * 3 + (z + h / 2 * L2) - sin(t + h / 2) * 3;
	double k4 = (y + h*k3)*(-4) - (z + h * L3) * 2 + cos(t + h) + sin(t + h) * 4;
	double L4 = (y + h*k3) * 3 + (z + h*L3) - sin(t + h) * 3;
	return (z + h / 6 * (L1 + L2 * 2 + L3 * 2 + L4));
}


void system_of_ode()
{
	double * t = new double[(b - a) / h + 1];
	t[0] = a;
	double * answer_y = new double[(b - a) / h + 1];
	answer_y[0] = yf;
	double * answer_z = new double[(b - a) / h + 1];
	answer_z[0] = zf;
	int i=1;
	while (i <= (b - a) / h)
	{
		answer_y[i] = calculate_y(t[i - 1], answer_y[i - 1], answer_z[i - 1]);
		answer_z[i] = calculate_z(t[i - 1], answer_y[i - 1], answer_z[i - 1]);
		t[i] = i*h;
		i++;
	}
	cout << "t" << setw(26) << "y1" << setw(26) << "y2" << endl;
	for (i = 0; i<((b - a) / h + 1); i++)
	{
		cout << setprecision(10) << t[i] << setw(26) << setprecision(10) << answer_y[i] << setw(26) << setprecision(10) << answer_z[i] << endl;
	}
}


int main()
{
	system_of_ode();
	return 0;
}
*/