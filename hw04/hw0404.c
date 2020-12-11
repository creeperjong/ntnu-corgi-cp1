#include <stdio.h>
#include <stdint.h>
#include "equivalent_r.h"

int main(){
    double R = 0;
    int32_t N = 0;
    printf("Please enter the resistance (1-100):");
    scanf("%lf",&R);
    printf("Please enter n (1-100):");
    scanf("%d",&N);
    if(R<1 || R>100 || N<1 || N>100){
        printf("Invalid Input!\n");
    }else{
        printf("Ans:%lf\n",Req(R,N));
    }
    return 0;
}