#pragma once

#include <stdio.h>
#include <stdint.h>
#include <math.h>

#define fori(x) for(int32_t i = 0;i < x;i++)
#define forj(x) for(int32_t j = 0;j < x;j++)
#define fork(x) for(int32_t k = 0;k < x;k++)



double slopeReg(int32_t **pointArr,int32_t pointNum);

double constReg(int32_t **pointArr,int32_t pointNum,double slope);