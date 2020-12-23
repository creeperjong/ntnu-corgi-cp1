#include <stdio.h>
#include <stdint.h>
#include "projection.h"

int main(){
    int32_t a = 0;
    int32_t b = 0;
    int32_t c = 0;
    int32_t d = 0;
    double x = 0;
    double y = 0;
    double z = 0;
    double* ptrX = &x;
    double* ptrY = &y;
    double* ptrZ = &z;
    
    printf("Please enter the plane:");
    scanf("%d %d %d %d",&a,&b,&c,&d);
    
    if(a == 0 && b == 0 && c == 0){
        printf("Invalid Input!\n");
    }else{
        printf("The plane is ");
        print_plane(a,b,c,d);
        printf("Please enter the point:");
        scanf("%lf %lf %lf",ptrX,ptrY,ptrZ);

        project(ptrX,ptrY,ptrZ,a,b,c,d);

        printf("The projection is (%.2lf,%.2lf,%.2lf)\n",x,y,z);
    }
    
    return 0;
}