#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

void main()
{
	double a = 1.5;
	double t = 0;
	while(1>0)
	{
		t = 2 * sqrt(double(1) / double(2 + a));
		if (abs(a - t) < 0.00000001)
		{
			cout << endl << setiosflags(ios::fixed) << setprecision(15) << t << endl;
			break;
		}
		else
		{
			a = t;
			cout << setiosflags(ios::fixed) << setprecision(15) << a << endl;
		}
	}
}


/*
void Steffensen()
{
	double a = 1.5;
	double t = 0;
	double b, c;
	while (1>0)
	{
		b = 2 * sqrt(double(1) / double(2 + a));
		c = 2 * sqrt(double(1) / double(2 + b));
		t = a - (b - a)*(b - a) / double(c - 2 * b + a);
		if (abs(a - t) < 0.00000001)
		{
			cout << endl << setiosflags(ios::fixed) << setprecision(15) << t << endl;
			break;
		}
		else
		{
			a = t;
			cout << setiosflags(ios::fixed) << setprecision(15) << a << endl;
		}
	}
}
*/

/*
int Newton()
{
	double a = 2;
	double t = 0;
	while (1>0)
	{
		t = (a + 3 / a) / 2;
		if (abs(a - t) < 0.0000000005)
		{
			cout << endl << setiosflags(ios::fixed) << setprecision(30) << t << endl;
			break;
		}
		else
		{
			a = t;
			cout << setiosflags(ios::fixed) << setprecision(30) << a << endl;
		}
	}
}
*/

/*
int gexian()
{
	double a = 1;
	double b = 2;
	double t = 0;
	while (1>0)
	{
		t = b - (2 * b*b*b - 5 * b - 1)*(b - a) / (2 * b*b*b - 5 * b - 2 * a*a*a + 5 * a);
		if (abs(a - t) < 0.000005)
		{
			cout << endl << setiosflags(ios::fixed) << setprecision(30) << t << endl;
			break;
		}
		else
		{
			a = t;
			cout << setiosflags(ios::fixed) << setprecision(30) << a << endl;
		}
	}
}
*/
