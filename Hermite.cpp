/*
#include <iostream>
using namespace std;
const int n = 3;
const double t = 0.25;
double lag_B(double *, int);
double lag_A(double, double *, int);
int main()
{
	double A[n] = { 0 };
	double B[n] = { 0 };
	double x[n] = { 0,1,2 };
	double f[n] = { 1,2.718,2.389 };
	double p[n] = { 1,2.718,2.389 };
	int i=0;
	for (i = 0; i < n; i++)
	{
		B[i] = lag_B(x, i);
		double temp = B[i] / (t - x[i]);
		A[i] = lag_A(temp, x, i);
	}
	for (i = 0; i < n; i++)
	{
		cout << "A" << i << "(0.25)=" << A[i] << endl;
	}
	for (i = 0; i < n; i++)
	{
		cout << "B" << i << "(0.25)=" << B[i] << endl;
	}
	double ans = 0;
	for (i = 0; i < n; i++)
	{
		ans = ans + A[i] * f[i] + B[i] * p[i];
	}
	cout << "f(0.25)=" << ans;
}

double lag_B(double * x, int i)
{
	double m = t - x[i];
	int j = 0;
	for (j = 0; j < n; j++)
	{
		if (j != i)
		{
			m = m * (t - x[j]) * (t - x[j]) / (x[i] - x[j]) / (x[i] - x[j]);
		}
	}
	return m;
}

double lag_A(double temp, double * x, int i)
{
	double q = 0;
	int j = 0;
	for (j = 0; j < n; j++)
	{
		if (j != i)
		{
			q = q + 1 / (x[i] - x[j]);
		}
	}
	return temp*(1 - 2 * (t - x[i])*q);
}
*/