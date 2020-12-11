#pragma once 

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define fori(x) for(int32_t i = x;i >= 0;i--)
#define forj(x) for(int32_t j = x;j >= 0;j--)

void polyPrint(int32_t *p,int32_t pdeg);

void polyPlus(int32_t *p1,int32_t *p2,int32_t p1deg,int32_t p2deg,int32_t cmp);

void polyMinus(int32_t *p1,int32_t *p2,int32_t p1deg,int32_t p2deg,int32_t cmp);

void polyMult(int32_t *p1,int32_t *p2,int32_t p1deg,int32_t p2deg);
