#include "projection.h"

void print_plane(int32_t a,int32_t b,int32_t c,int32_t d){

    char first = 'a';

    if(a != 0)first = 'a';
    else if(b != 0)first = 'b';
    else first = 'c';

    if(a != 0){
        if(first != 'a'){
            if(a > 0){
                printf("+ ");
            }
        }
        if(a > 0){
            if(a == 1){
                printf("x ");
            }else{
                printf("%dx ",a);
            }
        }else{
            if(a == -1){
                printf("- x ");
            }else{
                printf("- %dx",-a);
            }
        }
    }

    if(b != 0){
        if(first != 'b'){
            if(b > 0){
                printf("+ ");
            }
        }
        if(b > 0){
            if(b == 1){
                printf("y ");
            }else{
                printf("%dy ",b);
            }
        }else{
            if(b == -1){
                printf("- y ");
            }else{
                printf("- %dy",-b);
            }
        }
    }

    if(c != 0){
        if(first != 'c'){
            if(c > 0){
                printf("+ ");
            }
        }
        if(c > 0){
            if(c == 1){
                printf("z ");
            }else{
                printf("%dz ",c);
            }
        }else{
            if(c == -1){
                printf("- z ");
            }else{
                printf("- %dz",-c);
            }
        }
    }

    if(d != 0){
        if(d > 0){
            printf("+ %d ",d);
        }else{
            if(c == -1){
                printf("- 1 ");
            }else{
                printf("- %d ",-d);
            }
        }
    }

    printf("= 0\n");
}

void project(double *x,double *y,double *z,int32_t a,int32_t b,int32_t c,int32_t d){
    double t = 0;
    double tmpX = *x;
    double tmpY = *y;
    double tmpZ = *z;

    t = - a * tmpX - b * tmpY - c * tmpZ - d;
    t /= (a*a + b*b + c*c);

    *x += a * t;
    *y += b * t;
    *z += c * t;
}