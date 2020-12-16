#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define Start 0
#define S1 1
#define S2 2
#define S3 3
#define S4 4
#define S5 5
#define S6 6
#define Final 7

int main(){
	int32_t input = 0;
	int32_t state = 0;
	printf("Start\n");
	while(1){
		printf("Please enter an integer:");
		scanf("%d",&input);
		switch(state){
			case Start:
				if(input == 10 || input == 35){
					state = S1;
					printf("S1\n");
				}else if(input == 11){
					state = S3;
					printf("S3\n");
				}else if(input == 20 || input == 78){
					state = S5;
					printf("S5\n");
				}else{
					state = Start;
					printf("Start\n");
				}
				break;
			case S1:
				if(input == 19){
					state = S2;
					printf("S2\n");
				}else if(input == 12 || input == 36){
					state = S6;
					printf("S6\n");
				}else{
					state = S1;
					printf("S1\n");
				}
				break;
			case S2:
				if(input == 43){
					state = S2;
					printf("S2\n");
				}else if(input == 99){
					state = Final;
					printf("Final\n");
				}else{
					state = Start;
					printf("Start\n");
				}
				break;
			case S3:
				state = S4;
				printf("S4\n");
				break;
			case S4:
				state = S6;
				printf("S6\n");
				break;
			case S5:
				if(input == 1){
					state = S4;
					printf("S4\n");
				}else if(input == 2){
					state = S6;
					printf("S6\n");
				}else{
					state = Start;
					printf("Start\n");
				}
				break;
			case S6:
				if(input == 108){
					state = Final;
					printf("Final\n");
				}else{
					state = S5;
					printf("S5\n");
				}
				break;
		}
		if(state == Final){
			break;
		}
	}
	return 0;
}
