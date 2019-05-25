
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
const double hmax=0.1;
const double hmin=0.001;
const double TOL=0.0001;
const double a=0;
const double b=1;
const double yf=1;
void RKF45();
int main()
{
	RKF45();
	return 0;
}

double calculate_y(double y,double t,double h)
{
	double k1=h*(t*t-y+1);
	double k2=h*((t+h*0.25)*(t+h*0.25)-(y+k1*0.25)+1);
	double k3=h*((t+h*0.375)*(t+h*0.375)-(y+k1*3/32+k2*9/32)+1);
	double k4=h*((t+h*12/13)*(t+h*12/13)-(y+k1*1932/2197-k2*7200/2197+k3*7296/2197)+1);
	double k5=h*((t+h)*(t+h)-(y+k1*439/216-k2*8+k3*3680/513-k4*845/4104)+1);
	double k6=h*((t+h*0.5)*(t+h*0.5)-(y-k1*8/27+k2*2-k3*3544/2565+k4*1859/4104-k5*11/40)+1);
	return (y+k1*25/216+k3*1408/2565+k4*2197/4104-k5/5);
}

double calculate_u(double u,double y,double t,double h)
{
	double k1=h*(t*t-y+1);
	double k2=h*((t+h*0.25)*(t+h*0.25)-(y+k1*0.25)+1);
	double k3=h*((t+h*0.375)*(t+h*0.375)-(y+k1*3/32+k2*9/32)+1);
	double k4=h*((t+h*12/13)*(t+h*12/13)-(y+k1*1932/2197-k2*7200/2197+k3*7296/2197)+1);
	double k5=h*((t+h)*(t+h)-(y+k1*439/216-k2*8+k3*3680/513-k4*845/4104)+1);
	double k6=h*((t+h*0.5)*(t+h*0.5)-(y-k1*8/27+k2*2-k3*3544/2565+k4*1859/4104-k5*11/40)+1);
	return (u+k1*16/135+k3*6656/12825+k4*28561/56430-k5*9/50+k6*2/55);
}

void RKF45()
{
	double h=hmax;
	double t=a+h;
	double y[1000]={0};
	double u[1000]={0};
	double answer_y[1000]={0};
	double answer_t[1000]={0};
	double answer_u[1000]={0};
	y[0]=yf;
	u[0]=yf;
	answer_t[0]=a;
	answer_y[0]=yf;
	int i=1;
	double temp;
	while(t<=b&&h>=hmin)
	{
		y[i]=calculate_y(answer_y[i-1],answer_t[i-1],h);
		u[i]=calculate_u(answer_u[i-1],answer_y[i-1],answer_t[i-1],h);
		if(abs(y[i]-u[i])<=TOL)
		{
			answer_y[i]=y[i];
			answer_u[i]=y[i];
			answer_t[i]=t;
			t=t+h;
			i++;
		}
		else
		{
			temp=h;
			h=h*(sqrt(sqrt(TOL/(2*(abs(y[i]-u[i]))/h))));
		}
	}
	if(h<hmin&&t<=b)
	{
		h=temp;
		while(t<=b)
		{
			answer_y[i]=calculate_y(answer_y[i-1],answer_t[i-1],h);
			answer_t[i]=t;
			t=t+h;
			i++;
		}
	}
	cout << "t" << setw(26) << "y(t)" << endl;
	cout<<setprecision(10)<<answer_t[0]<<setw(26)<<setprecision(10)<<answer_y[0]<<endl;
	for(i=1;answer_t[i]!=0;i++)
	{
		cout<<setprecision(10)<<answer_t[i]<<setw(26)<<setprecision(10)<<answer_y[i]<<endl;
	}
}




