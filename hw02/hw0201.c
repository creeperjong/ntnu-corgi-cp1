#include <stdio.h>
#include <stdint.h>
#include <limits.h>

int main(){
	int32_t a=0;
	int32_t b=0;
	int32_t c=0;
	int32_t d=0;
	printf("Please enter a quadratic polynomial (a,b,c):");
	scanf("%d,%d,%d",&a,&b,&c);
	if(a*2<=SHRT_MAX && a*2>=SHRT_MIN){ 
		if(b*2<=SHRT_MAX && b*2>=SHRT_MIN){
			if(c*2<=SHRT_MAX && c*2>=SHRT_MIN){ //限制輸入值：將最大值/2以避免d溢值
				d=b*b-4*a*c;//仍會有些許數值未能考慮ex:a=1,b=0,c=2147483648
				if(d>0){
					printf("Two distinct real roots.\n");
				}else if(d==0){
					printf("One real root.\n");
				}else{
					printf("No real root.\n");
				}
			}else{
				printf("Error\n");
			}
		}else{
			printf("Error\n");
		}
	}else{
		printf("Error\n");
	}
	return 0;
}

