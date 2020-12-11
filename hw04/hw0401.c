#include <stdio.h>
#include <stdint.h>
#include "roman_calculator.h"

int main(){
    int32_t input = 0;
    printf("Please enter an integer (1~3000):");
    scanf("%d",&input);
    if(input > 3000 || input < 1){
        printf("Invalid Input!\n");
    }else{
        printf("%d:%s\n",input,roman(input));
    }
    return 0;
}