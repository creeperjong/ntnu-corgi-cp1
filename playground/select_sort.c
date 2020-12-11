#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

void select_sort(int32_t* arr,int32_t (*min)(int32_t* arr,int32_t i));
int32_t min(int32_t* arr,int32_t i);

int32_t min(int32_t* arr,int32_t i){
    int32_t min_i = i;
    for(int32_t j = i + 1;j < 10;j++){
        if(arr[j] < arr[min_i]){
            min_i = j;
        }
    }
    return min_i;
}

void select_sort(int32_t* arr,int32_t (*min)(int32_t* arr,int32_t i)){
    int32_t tmp = 0;
    int32_t min_i = 0;
    for(int32_t i = 0;i < 10;i++){
        min_i = min(arr,i);
        if(arr[i] > arr[min_i]){
            tmp = arr[i];
            arr[i] = arr[min_i];
            arr[min_i] = tmp;
        }
    }
}

int main(){
    srand(time(NULL));
    int32_t arr[10] = {0};
    for(int32_t i = 0;i < 10;i++){
        arr[i] = rand() % 1000;
    }
    printf("Before:");
    for(int32_t i = 0;i < 10;i++){
        printf("%d ",arr[i]);
    }
    select_sort(arr,min);
    printf("\nAfter:");
    for(int32_t i = 0;i < 10;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    return 0;
}