#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int32_t minArrayDelection(const int* numbers, int32_t arraySize,int32_t p);
int32_t minArrayDelectionDiscon(const int* numbers, int32_t arraySize,int32_t p);
int32_t** findIndex(int32_t arraySize,int32_t length);
int32_t numOfRow(int32_t upper,int32_t lower);
int32_t roundIndex(int32_t *indexArr,int32_t length,int32_t arrSize);

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

int32_t minArrayDelectionDiscon(const int* numbers, int32_t arraySize,int32_t p){
    int32_t sum = 0;
    int32_t sumSubarr = 0;
    int32_t **indexArray = NULL;

    for(int32_t i = 0;i < arraySize;i++){
        sum += numbers[i];
    }
    
    if(sum % p == 0){
        return 0;
    }else{
        for(int32_t i = 1;i < arraySize;i++){   //determine array's length
            indexArray = findIndex(arraySize,i);
            for(int32_t j = 0;j < numOfRow(arraySize,i);j++){
                for(int32_t k = 0;k < i;k++){
                    sumSubarr += numbers[indexArray[j][k]];
                }
                if((sum - sumSubarr) % p == 0){
                    for(int32_t k = 0;k < i;k++){
                        printf("%d ",indexArray[j][k]);
                    }
                    printf("\n");
                    free(indexArray);
                    return i;
                }
                sumSubarr = 0;
            }
        }
    }
    free(indexArray);
    return -1;
}

int32_t** findIndex(int32_t arraySize,int32_t length){
    
    //Initialize,use 2D array to store all possibility
    //Row means the number of possibility
    //Column means the number of required array's length

    int32_t **indexArr = NULL;
    int32_t row = numOfRow(arraySize,length);

    indexArr = (int32_t**)malloc(row * sizeof(int32_t*));
    for(int32_t i = 0;i < row;i++){
        indexArr[i] = (int32_t*)malloc(length * sizeof(int32_t));
    }

    //start to find index
    //The rule:to begin with first row which is 0,1,2,....,length-1
    //the element has the highest index +1 when moving to next row
    //when any element is larger than arraySize
    //it needs to be carried until the condition above doesn't happen

    int32_t roundInd = 0;

    for(int32_t i = 0;i < row;i++){
        if(i == 0){
            for(int32_t j = 0;j < length;j++){
                indexArr[i][j] = j; //first row: fill 0~length in order
            }
        }else{
            for(int32_t j = 0;j < length;j++){
                indexArr[i][j] = indexArr[i-1][j];  //duplicate the previous row's content
            }
            indexArr[i][length-1]++;    //the highest index's element + 1
            while(1){   //use infinite loop to achieve the comment @ line 89
                roundInd = roundIndex(indexArr[i],length,arraySize);
                if(roundInd > 0){   //roundInd != 0 since we had restricted the number of row correctly
                    indexArr[i][roundInd-1]++;  //carried
                    indexArr[i][roundInd] = indexArr[i][roundInd-1] + 1;    //it doesn't matter when it overflew again
                }else{
                    break;
                }
            }
            if(indexArr[i][length-1] > arraySize-1){    //we only need to check the highest index
                roundInd = roundIndex(indexArr[i],length,arraySize);
                for(int32_t j = roundInd;j < length;j++){
                    indexArr[i][j] = indexArr[i][j-1] + 1;  //processing like line 95
                }
            }
        }
    }
    /*for(int32_t i = 0;i < row;i++){
        for(int32_t j = 0;j < length;j++){
            printf("%d ",indexArr[i][j]);
        }
        printf("\n");
    }*/
    return indexArr;
}

int32_t numOfRow(int32_t upper,int32_t lower){  //C upper 取 lower的函式，計算所有的可能數 
    if(upper == lower || lower == 0){
        return 1;
    }else{
        return numOfRow(upper-1,lower) + numOfRow(upper-1,lower-1); //Pascal Theorem
    }
} 

int32_t roundIndex(int32_t *indexArr,int32_t length,int32_t arrSize){ //to find a lowest index needed to be carry
    for(int32_t i = 0;i < arrSize;i++){
        if(indexArr[i] > arrSize){
            return i;
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

    printf("Result(Continuous):%d\n",minArrayDelection(arr,arrSize,p));
    printf("Result(Discontinuous):%d\n",minArrayDelectionDiscon(arr,arrSize,p));

    free(arr);

    return 0;
}