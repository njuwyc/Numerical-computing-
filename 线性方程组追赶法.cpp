//追赶法
#include <iostream>
#include <iomanip>
using namespace std;
const int n = 5;
void zhuigan(double (*A)[n], int size, double *b)
{
	int i = 0;
	double x[n] = { 0 };
	double y[n] = { 0 };
	double L[n][n] = { 0 };
	for (i = 1; i < n; i++)
	{
		L[i][i - 1] = A[i][i - 1];
	}
	double U[n][n] = { 0 };
	for (i = 0; i < n; i++)
	{
		U[i][i] = 1;
	}
	i = 0;
	L[0][0] = A[0][0];
	double p = L[0][0];
	while (i < n - 1)
	{
		U[i][i + 1] = A[i][i + 1] / p;
		L[i + 1][i + 1] = A[i + 1][i + 1] - A[i + 1][i] * U[i][i + 1];
		p = L[i + 1][i + 1];
		i++;
	}

	cout << "将满足优对角条件的三对角系数矩阵A分解为A=L*U,其中L矩阵为：" << endl;
	for (i = 0; i < n; i++)
	{
		int j = 0;
		for (j = 0; j < n; j++)
		{
			cout << setw(12) << L[i][j];
		}
		cout << endl;
	}
	cout << "U矩阵为：" << endl;
	for (i = 0; i < n; i++)
	{
		int j = 0;
		for (j = 0; j < n; j++)
		{
			cout << setw(12) << U[i][j];
		}
		cout << endl;
	}

	i = 0;
	y[0] = b[0] / L[0][0];
	for (i = 1; i < n; i++)
	{
		y[i] = (b[i] - y[i - 1] * L[i][i - 1]) / L[i][i];
	}

	cout << "解得y向量为：" << endl;
	for (i = 0; i < n; i++)
	{
		cout << y[i] << endl;
	}
	
	i = 0;
	x[n - 1] = y[n - 1] / U[n - 1][n - 1];
	for (i = n - 2; i >= 0; i--)
	{
		x[i] = (y[i] - x[i + 1] * U[i][i + 1]) / U[i][i];
	}

	cout << "解得x向量为：" << endl;
	for (i = 0; i < n; i++)
	{
		cout << x[i] << endl;
	}
}

int main()
{
	double A[n][n] = { {2,1,0,0,0},{1,4,1,0,0},{0,1,4,1,0},{0,0,1,4,1},{0,0,0,1,4} };
	double b[n] = { 1,-2,2,-2,3 };
	zhuigan(A, n, b);
}
