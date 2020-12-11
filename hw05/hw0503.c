#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "poly.h"

int main(){
    
    //Initialize

    int32_t p1deg = 0;
    int32_t p2deg = 0;
    int32_t *p1 = NULL;
    int32_t *p2 = NULL;
    
    printf("Please enter p1 degree:");
    scanf("%d",&p1deg);
    

    if(p1deg<0){
        printf("Invalid Input!\n");
        return 0;
    }else{
        p1 = calloc(p1deg + 1,sizeof(int32_t));
    }
    
    printf("Please enter p1 coefficients:");
    
    fori(p1deg){
        scanf("%d",&p1[i]);
    }

    printf("Please enter p2 degree:");
    scanf("%d",&p2deg);
    
    if(p2deg<0){
        printf("Invalid Input!\n");
        return 0;
    }else{
        p2 = calloc(p2deg + 1,sizeof(int32_t));
    }
    
    printf("Please enter p2 coefficients:");
    
    fori(p2deg){
        scanf("%d",&p2[i]);
    }

    //print p1 & p2

    printf("p1: ");
    polyPrint(p1,p1deg);
    printf("p2: ");
    polyPrint(p2,p2deg);

    //compare p1 & p2

    int32_t cmp = 0;

    if(p1deg > p2deg){
        cmp = 1;
    }else if(p1deg == p2deg){
        cmp = 2;
    }else{
        cmp = 3;
    }
    
    //print p1 + p2

    printf("p1 + p2: ");
    polyPlus(p1,p2,p1deg,p2deg,cmp);

    //print p1 - p2

    printf("p1 - p2: ");
    polyMinus(p1,p2,p1deg,p2deg,cmp);

    //print p1 * p2

    printf("p1 * p2: ");
    polyMult(p1,p2,p1deg,p2deg);

    free(p1);
    free(p2);
    return 0;
}