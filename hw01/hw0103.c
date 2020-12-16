#include <stdio.h>
#include <stdint.h>

int main(){
	float g=0.0;
	float t=0.0;
	float v=0.0;
	float a=0.0;
	printf("Please enter the acceleration due to gravity:");
	scanf("%f",&g);
	printf("Please enter the time(s):");
	scanf("%f",&t);
	v = g*t;
	a = g*t*t/2.0;
	printf("Final velocity:%.2f(m/s)\nThe altitude:%.3f(m)\n",v,a);
	return 0;
}
