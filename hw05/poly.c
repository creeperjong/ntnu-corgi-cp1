#include "poly.h"

void polyPrint(int32_t *p,int32_t pdeg){
    
    //if only const. exists, we only need to print it
    
    if(pdeg == 0){
        if(p[0] < 0){
            printf("- %d",-p[0]);
        }else{
            printf("%d",p[0]);
        }
    }else{

        //if degree is larger than 0, print the highest order term
        
        if(p[pdeg] != 0){
            if(pdeg == 1){  //degree = 1
                if(p[pdeg] == 1){
                    printf("x ");
                }else if(p[pdeg] == -1){
                    printf("- x ");
                }else{
                    if(p[pdeg] > 0){
                        printf("%dx ",p[pdeg]);
                    }else{
                        printf("- %dx ",-p[pdeg]);
                    }
                }
            }else{ //degree != 1
                if(p[pdeg] == 1){
                    printf("x^%d ",pdeg);
                }else if(p[pdeg] == -1){
                    printf("- x^%d ",pdeg);
                }else{
                    if(p[pdeg] > 0){
                        printf("%dx^%d ",p[pdeg],pdeg);
                    }else{
                        printf("- %dx^%d ",-p[pdeg],pdeg);
                    }
                }
            }
        }

        //then process the rest terms of th polynomial 

        fori(pdeg - 1){
            if(p[i] == 0){  //skip when coefficient = 0
                continue;
            }else{
                if(i == 0){ //const.
                    if(p[i] < 0){
                        printf("- %d",-p[i]);
                    }else{
                        printf("+ %d",p[i]);
                    }
                }else if(i == 1){   //coefficient = 0
                    if(p[i] == 1){
                        printf("+ x ");
                    }else if(p[i] == -1){
                        printf("- x ");
                    }else{
                        if(p[i] > 0){
                            printf("+ %dx ",p[i]);
                        }else{
                            printf("- %dx ",-p[i]);
                        }
                    }
                }else{
                    if(p[i] == 1){
                        printf("+ x^%d ",i);
                    }else if(p[i] == -1){
                        printf("- x^%d ",i);
                    }else{
                        if(p[i] > 0){
                            printf("+ %dx^%d ",p[i],i);
                        }else{
                            printf("- %dx^%d ",-p[i],i);
                        }
                    }
                }
            }
        }
    }
    printf("\n");
}

void polyPlus(int32_t *p1,int32_t *p2,int32_t p1deg,int32_t p2deg,int32_t cmp){

    int32_t *poly_result = NULL;
    int32_t size = 0;
    
    if(cmp == 1 || cmp == 2){
        size = p1deg + 1;
        poly_result = calloc(size,sizeof(int32_t));
        fori(p1deg){
            if(i > p2deg){
                poly_result[i] = p1[i];
            }else{
                poly_result[i] = p1[i] + p2[i];
            }
        }
    }else{
        size = p2deg + 1;
        poly_result = calloc(size,sizeof(int32_t));
        fori(p2deg){
            if(i > p1deg){
                poly_result[i] = p2[i];
            }else{
                poly_result[i] = p1[i] + p2[i];
            }
        }
    }
    
    polyPrint(poly_result,size-1);

    free(poly_result);
}

void polyMinus(int32_t *p1,int32_t *p2,int32_t p1deg,int32_t p2deg,int32_t cmp){

    int32_t *poly_result = NULL;
    int32_t size = 0;
    
    if(cmp == 1 || cmp == 2){
        size = p1deg + 1;
        poly_result = calloc(size,sizeof(int32_t));
        fori(p1deg){
            if(i > p2deg){
                poly_result[i] = p1[i];
            }else{
                poly_result[i] = p1[i] - p2[i];
            }
        }
    }else{
        size = p2deg + 1;
        poly_result = calloc(size,sizeof(int32_t));
        fori(p2deg){
            if(i > p1deg){
                poly_result[i] = -p2[i];
            }else{
                poly_result[i] = p1[i] - p2[i];
            }
        }
    }
    
    polyPrint(poly_result,size-1);

    free(poly_result);
}

void polyMult(int32_t *p1,int32_t *p2,int32_t p1deg,int32_t p2deg){

    int32_t *poly_result = NULL;
    int32_t size = 0;

    size = p1deg + p2deg + 1;
    poly_result = calloc(size,sizeof(int32_t));

    fori(p1deg){
        forj(p2deg){
            poly_result[i + j] += p1[i] * p2[j];
        }
    }

    polyPrint(poly_result,size - 1);

    free(poly_result);
}