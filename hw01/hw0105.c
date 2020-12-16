#include <stdio.h>
#include <stdint.h>

int main()
{
	int32_t a=0;
	printf("Please enter an integer:");
	scanf("%d",&a);
	printf("%d:%x\n",a,a);//%x
	return 0;
}
