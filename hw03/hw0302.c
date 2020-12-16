#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int main(){
	char digit[10];
	int32_t length = 0;
	int32_t temp = 0;
	printf("Please enter a natural number:");
	scanf("%s", digit);
	if(atol(digit)>UINT_MAX || atol(digit)<0){
		printf("Error\n");
	}else{
		length = strlen(digit);
		temp = digit[0];
	 	digit[0] = digit[length-1];
		digit[length-1] = temp;
		printf("%s\n",digit);
	}
	return 0;
}
