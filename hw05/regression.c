#include "regression.h"


double slopeReg(int32_t **pointArr,int32_t pointNum){
    
    double numerator = 0;
    double denominator = 0;
    double avgX = 0;
    double avgY = 0;

    //average

    fori(pointNum){
        avgX += pointArr[i][0];
        avgY += pointArr[i][1];
    }
    avgX /= pointNum;
    avgY /= pointNum;

    //assign numerator & denominator

    fori(pointNum){
        numerator += (pointArr[i][0] - avgX) * (pointArr[i][1] - avgY);
        denominator += pow((pointArr[i][0] - avgX),2);
    }

    return numerator/denominator;
}

double constReg(int32_t **pointArr,int32_t pointNum,double slope){
    double avgX = 0;
    double avgY = 0;
    double constNum = 0;

    //average

    fori(pointNum){
        avgX += pointArr[i][0];
        avgY += pointArr[i][1];
    }
    avgX /= pointNum;
    avgY /= pointNum;

    //solve constant number

    constNum = avgY - slope * avgX;

    return constNum;
}