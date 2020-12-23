#include "rotation.h"

void rotate(double *x,double *y,double theta){
    double tmpX = *x;
    double tmpY = *y;

    (*x) = (tmpX) * cos(theta * M_PI / -180.0) - (tmpY) * sin(theta * M_PI / -180.0);
    (*y) = (tmpX) * sin(theta * M_PI / -180.0) + (tmpY) * cos(theta * M_PI / -180.0);
}