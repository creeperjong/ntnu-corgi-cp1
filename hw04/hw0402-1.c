#include <stdio.h>
#include <stdint.h>
#include "hanoi_steps_analyzer.h"

int main(){
    int32_t disk_number = 0;
    printf("Please enter the disk number (2-20):");
    scanf("%d",&disk_number);
    if(disk_number>20 || disk_number<2){
        printf("Invalid Input!\n");
    }else{
        hanoi_steps_recrusive(disk_number,1,2,3);
    }
    return 0;
}