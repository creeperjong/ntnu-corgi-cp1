#include "array_sort.h"

#define fori(x,y) for(int32_t i = x;i < y;i++)
#define forj(x,y) for(int32_t j = x;j < y;j++)

int32_t* sort(int32_t *arr,int32_t arr_size){

    int32_t odd_size = 0; 
    int32_t even_size = 0;
    int32_t *arr_result = calloc(arr_size,sizeof(int32_t));
    int32_t index = 0;
    
    //count & separate odd and even

    fori(0,arr_size){
        if(*(arr+i) % 2 == 1){
            *(arr_result + odd_size) = *(arr+i);
            odd_size++;
        }else{
            *(arr_result + arr_size - 1 - even_size) = *(arr+i);
            even_size++;
        }
    }

    //bubble sort

    int32_t tmp = 0;

    fori(0,odd_size){
        forj(i+1,odd_size){
            if(arr_result[i]>arr_result[j]){
                tmp = arr_result[i];
                arr_result[i] = arr_result[j];
                arr_result[j] = tmp;
            }
        }
    }
    fori(odd_size,arr_size){
        forj(i+1,arr_size){
            if(arr_result[i]<arr_result[j]){
                tmp = arr_result[i];
                arr_result[i] = arr_result[j];
                arr_result[j] = tmp;
            }
        }
    }
    return arr_result;   
}
