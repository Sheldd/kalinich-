#include <iostream>
#include <cmath>
using namespace std;

double m1_sqr=0.09,
	   m2_sqr=0.25,
	   q1=0,
	   q2=0.14;


double Func(double const &alpha, double const & t, 
			double const & a,double const & b,
			double const & m,double const & n,
			double const & lambda);

double MAX(double (*f)(double const &, double const & , double const & ,double const & ,double const & ,double const & ,double const &),
			double const & a,double const & b,
			double const & m,double const & n,
			double const & lambda);


int main() {
	
	
	
	
}



double Func(double const &alpha, double const & t, double const & a,double const & b,double const & m,double const & n,double const & lambda)
{
	double R=alpha*q1+(1-alpha)*q2;
	double D=alpha*(q1*q1*m1_sqr)+(1-alpha)*(q2*q2+m2_sqr)-R*R;
	
	return pow(alpha,a)*pow(1-alpha,b)*pow(t,m)/pow(1+t,n)*exp(-t*(D+R*R/(1+t))/lambda);
	
}

double MAX(double (*f)(double const &, double const & , double const & ,double const & ,double const & ,double const & ,double const &),
			double const & a,double const & b,
			double const & m,double const & n,
			double const & lambda)
			{
				double alpha=0.5;
				double t=50;
				//double accurancy=0.01;
				double h=0.01;
				
				double proiz_Alpha=0;
				double proiz_T=0;
				do
				{
					proiz_Alpha=(f(alpha+h,t,a,b,m,n,lambda)-f(alpha,t,a,b,m,n,lambda))/h;
					proiz_T=(f(alpha,t+h,a,b,m,n,lambda)-f(alpha,t,a,b,m,n,lambda))/h;	
					alpha+=proiz_Alpha;
					t+=proiz_T;
				}while(proiz_Alpha*proiz_Alpha+proiz_T*proiz_T>h*h)
				
				
				return f(alpha,t,a,b,m,n,lambda);
				
				
			}
