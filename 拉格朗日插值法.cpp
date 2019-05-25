#include <iostream>
#include<cmath>
#include <iomanip>
using namespace std;
const int n = 5;
const double pi = 3.1415926535897;
int main()
{
	double q[n] = { 0 };
	double x[n] = { cos(pi*0.1),cos(pi*0.3),cos(pi*0.5),cos(pi*0.7),cos(pi*0.9) };
	int i, j = 0;
	double f[n] = { 0 };
	for (i = 0; i < n; i++)
	{
		cout << setw(20) << setprecision(10) << x[i];
	}
	cout << endl;
	for (i = 0; i < n; i++)
	{
		f[i] = x[i] * exp(x[i]);
		q[i] = f[i];
		for (j = 0; j < n; j++)
		{
			if (j != i)
			{
				q[i] = q[i] / (x[i] - x[j]);
			}
		}
		cout << q[i] << endl;
	}
	return 0;
}
