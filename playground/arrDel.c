#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int32_t minArrayDelection(const int* numbers, int32_t arraySize,int32_t p);

int32_t minArrayDelection(const int* numbers, int32_t arraySize,int32_t p){
    int32_t sum = 0;
    int32_t sumSubarr = 0;

    for(int32_t i = 0;i < arraySize;i++){
        sum += numbers[i];
    }
    
    if(sum % p == 0){
        return 0;
    }else{
        for(int32_t i = 1;i < arraySize;i++){   //determine array's length
            for(int32_t j = 0;j <= arraySize - i;j++){  //first index in array
                for(int32_t k = j;k < j + i;k++){   //travel throughout the array to sum
                    sumSubarr += numbers[k];
                }
                if((sum - sumSubarr) % p == 0){
                    return i;
                }
                sumSubarr = 0;
            }
        }
    }
    return -1;
}

int main(){
    int32_t *arr = NULL;
    int32_t arrSize = 0;
    int32_t p = 0;

    printf("Please enter array size:");
    scanf("%d",&arrSize);
    arr = calloc(arrSize,sizeof(int32_t));

    printf("Please enter array:");
    for(int32_t i = 0;i < arrSize;i++){
        scanf("%d",&arr[i]);
    }

    printf("Please enter p:");
    scanf("%d",&p);

    printf("Result:%d\n",minArrayDelection(arr,arrSize,p));
}