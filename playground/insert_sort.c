#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

void insert_sort(int32_t* arr);

void insert_sort(int32_t* arr){
    int32_t tmp = 0;
    int32_t j = 0;
    for(int32_t i = 0;i < 10;i++){
        tmp = arr[i];
        j = i - 1;
        while(j>=0 && arr[j] > tmp){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = tmp;
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
    insert_sort(arr);
    printf("\nAfter:");
    for(int32_t i = 0;i < 10;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    return 0;
}