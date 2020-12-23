#include <stdio.h>
#include <stdint.h>
#include "rotation.h"

int main(){
    
    double x = 0;
    double y = 0;
    double* ptrX = &x;
    double* ptrY = &y;
    double theta = 0;

    printf("Please enter a point:");
    scanf("%lf %lf",ptrX,ptrY);
    printf("Please enter theta (0-360):");
    scanf("%lf",&theta);
    if(theta > 360 || theta < 0){
        printf("Invalid Input!");
    }else{
        rotate(ptrX,ptrY,theta);
        printf("%.3lf %.3lf\n",x,y);
    }
    return 0;
}