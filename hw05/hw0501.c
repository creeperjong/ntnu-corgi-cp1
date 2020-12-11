#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "test.h"
#include "array_sort.h"

#define for(x) for(int32_t i = 0;i < x;i++)

int main(){
    printf("Before:\n");
    for(array_size){
        printf("%d ",array[i]);
    }
    printf("\n");
    printf("After:\n");

    int32_t* sortedArray = sort(array,array_size);
    for(array_size){
        printf("%d ",*(sortedArray+i));
    }
    printf("\n");
    free(sortedArray);
    return 0;
}