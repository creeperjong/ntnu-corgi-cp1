#include "equivalent_r.h"

double Req(double r,int32_t n){
    if(n == 1){
        return r*2;
    }else{
        return r + ( Req(r,n-1) * r) / ( Req(r,n-1) + r);
    }
}
