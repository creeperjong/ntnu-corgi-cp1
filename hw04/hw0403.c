#include <stdio.h>
#include <stdint.h>
#include "e_calculator.h"

int main(){
    int32_t k = 0;
    printf("k-th order Taylor polynomial for e\n");
    printf("Please enter k:");
    scanf("%d",&k);
    if(k<1){
        printf("Invalid Input!\n");
    }else{
        printf("%.60lf\n",e_value(k));
    }
    return 0;
}