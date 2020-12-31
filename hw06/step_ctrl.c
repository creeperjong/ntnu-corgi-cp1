#include "step_ctrl.h"

void action(int32_t* act,int32_t* ptrIndex,int32_t input){
    if(input == -1){
        if((*ptrIndex) == 0){
            printf("Invalid Input!\n");
        }else{
            (*ptrIndex)--;
        }
    }else if(input == -2){
        if((*ptrIndex) == 10 || act[*ptrIndex] == 0){
            printf("Invalid Input!\n");
        }else{
            (*ptrIndex)++;
        }
    }else if(input > 0){
        if((*ptrIndex) == 10){
            for(int32_t i = 0;i < 9;i++){
                act[i] = act[i+1];
            }
            (*ptrIndex) = 9;
        }

        act[*ptrIndex] = input;
        (*ptrIndex)++;

        if(*ptrIndex < 10){
            for(int32_t i = *ptrIndex;i < 9;i++){
                act[i] = 0;
            }
        }
    }else{
        printf("Invalid Input!\n");
    }

    /*for(int32_t i = 0;i < *ptrIndex;i++){
        printf("%d ",act[i]);
    }
    printf("\n");*/
}