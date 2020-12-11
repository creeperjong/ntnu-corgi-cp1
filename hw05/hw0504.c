#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "regression.h"


int main(){
     
    int32_t pointNum = 0;
    printf("Please enter the point number:");
    scanf("%d",&pointNum);

    //Initialize

    int32_t **pointArr = (int32_t**) malloc(pointNum * sizeof(int32_t*));

    fori(pointNum){
        pointArr[i] = (int32_t*) malloc(2 * sizeof(int32_t));
    }

    //scan the data

    fori(pointNum){
        printf("Please enter Point %d:",i+1);
        scanf("%d %d",&pointArr[i][0],&pointArr[i][1]);
    }


    //chech if it is non-relative

    int32_t isRelative = 1;

    fori(pointNum){
        if(pointArr[0][0] != pointArr[i][0]){
            isRelative = 1;
            break;
        }else{
            isRelative = 0;
        }
    }

    //printf result

    double m = 0;
    double k = 0;

    m = slopeReg(pointArr,pointNum);
    k = constReg(pointArr,pointNum,m);

    if(!isRelative){
        printf("Non-relative data.The regression equation doesn't exist\n");
    }else{
        printf("Regression Equation: y = ");
        if(m == 0){
            printf("%lf",k);
        }else{
            if(m == 1){
                printf("x ");
            }else if(m == -1){
                printf("-x ");
            }else{
                printf("%lfx ",m);
            }

            if(k > 0){
                printf("+ %lf",k);
            }else if(k < 0){
                printf("- %lf",-k);
            }
        }
        printf("\n");
    }
    free(pointArr);
    return 0;
}