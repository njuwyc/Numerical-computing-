#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
const int m = 4;
const int n = 3;
const int r = 3;

double calculate_erfanshu(double * t)
{
	int i = 0;
	double sum = 0;
	for (i = 0; i < m; i++)
	{
		sum = sum + t[i] * t[i];
	}
	double result = sqrt(sum);
	return result;
}

double calculate_u(double *p, double *q)
{
	int i = 0;
	double result = 0;
	for (i = 0; i < m; i++)
	{
		result = result + p[i] * q[i];
	}
	return result;
}

int main()
{
	double A[m][n] = { {1,-1,1},{0,-2,-1},{1,1,1},{0,2,1} };
	double A_2[n][m] = { {1,0,1,0},{-1,-2,1,2},{1,-1,1,1} };
	double Q[m][r] = { 0 };
	double Q_2[r][m] = { 0 };
	double R[r][r] = { 0 };
	int i = 0;
	int j = 0;
	int k = 0;
	int s = 0;
	for (i = 0; i < r; i++)
	{
		R[i][i] = calculate_erfanshu(A_2[i]);
		for (k = 0; k < m; k++)
		{
			Q_2[i][k] = A_2[i][k] / R[i][i];
		}
		for (j = i + 1; j < r; j++)
		{
			R[i][j] = calculate_u(Q_2[i], A_2[j]);
			for (s = 0; s < m; s++)
			{
				A_2[j][s] = A_2[j][s] - R[i][j] * Q_2[i][s];
			}
		}
	}

	cout << "¾ØÕóQÎª£º" << endl;
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			Q[i][j] = Q_2[j][i];
			cout << setw(20) << setprecision(10) << Q[i][j] << setw(20);
		}
		cout << endl;
	}

	cout << endl << "¾ØÕóRÎª£º" << endl;
	for (i = 0; i < r; i++)
	{
		for (j = 0; j < r; j++)
		{
			cout << setw(20) << setprecision(10) << R[i][j] << setw(20);
		}
		cout << endl;
	}
}
