#include <stdio.h>
#include <stdint.h>
#include "step_ctrl.h"

int main(){

    int32_t act[10] = {0};
    int32_t index = 0;
    int32_t* ptrIndex = &index;
    int32_t input = 0;

    while(1){
        printf("input:");
        scanf("%d",&input);
        if(input == 0){
            break;
        }else{
            action(act,ptrIndex,input);
        }
    }

    printf("Result: ");
    for(int32_t i = 0;i < *ptrIndex;i++){
        printf("%d ",act[i]);
    }
    printf("\n");
    return 0;
}