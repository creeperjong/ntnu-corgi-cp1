#include <stdio.h>
#include <stdint.h>
#include <math.h>

double a = 0.0;
double b = 0.0;
double c = 0.0;
double s = 0.0;
double t = 0.0;
int32_t n = 0;

double equation(double);
double integrate(double);
double Riemann(int32_t);

double equation(double x_input){
	double result = 0.0;
	result = a*pow(x_input,2)+b*x_input+c;
	return result;
}

double integrate(double bound){
	double integral = 0.0;
	integral = a/3*pow(bound,3) + b/2*pow(bound,2) + c*bound;
	return integral;
}

double Riemann(int32_t n_input){
	double Rsum = 0.0;
	for(int32_t i = 0;i<=n_input-1;i++){
		Rsum += (t-s)/n_input*equation(s+(t-s)*i/n_input);
	}
	return Rsum;
}

int main(){
	printf("Please enter a quadratic polynomial:");
	scanf("%lf,%lf,%lf",&a,&b,&c);
	printf("The polynomial is ");
	//輸出方程式
	if(a!=0){
		if(a==1){
			printf("x^2");
		}else if(a==-1){
			printf("-x^2");
		}else{
			printf("%.2lfx^2",a);
		}
	}
	if(b>0 && a!=0){
		printf("+");
	}
	if(b!=0){
		if(b==1){
			printf("x");
		}else if(b==-1){
			printf("-x");
		}else{
			printf("%.2lfx",b);
		}
	}
	if((a!=0 || b!=0) && c>0){
	printf("+");
	}
	if(c!=0){
		printf("%.2lf",c);
	}
	if(a==0 && b==0 && c==0){
		printf("Invalid Input!\n");
	}
	printf("\n");
	printf("Please enter the interval [s,t]:");
	scanf("%lf,%lf",&s,&t);
	if(t<s){
		printf("Invalid Input!\n");
		return 0;
	}
	printf("The integral:%lf\n",integrate(t)-integrate(s));
	for(int32_t expo = 1;expo<=16;expo++){
		n = pow(2,expo);
		printf("The Riemann sum of n=%d:%lf\n",n,Riemann(n));
	}
	return 0;
}
