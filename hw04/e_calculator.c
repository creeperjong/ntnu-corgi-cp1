#include "e_calculator.h"

double e_value(double k){
    if(k == 1){
        return 2;
    }else{
        double temp_value = 1;
        for(int32_t i = k;i>0;i--){
            temp_value *= 1.0/i;
        }
        return (temp_value + e_value(k-1));
    }
}