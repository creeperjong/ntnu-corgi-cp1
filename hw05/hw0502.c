#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "determinant.h"
#include "test2.h"

#define fori(x) for(int32_t i = 0;i < x;i++)
#define forj(x) for(int32_t j = 0;j < x;j++)

int main(){
    printf("The matrix is\n");
    fori(4){
        forj(4){
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }
    printf("The determinant is %d\n",det(matrix));
    return 0;
}