#include <stdio.h>
#include <stdint.h>

int main(){
	int32_t a=0;
	int32_t b=0;
	int32_t c=0;
	int32_t d=0;
	int32_t e=0;
	int32_t input=0;
	printf("Please enter a 5-digits integer:");
	scanf("%d",&input);
	/*a = input/10000;
	b = input/1000-10*a;
	c = input/100-100*a-10*b;
	d = input/10-1000*a-100*b-10*c;
	e = input/1-10000*a-1000*b-100*c-10*d;
	*/
	a = input/10000;
	b = input%10000/1000;
	c = input%1000/100;
	d = input%100/10;
	e = input%10/1; 
	printf("Result:%d\n",a*b*c*d*e);
	return 0;
}
