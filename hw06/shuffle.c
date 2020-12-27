#include "shuffle.h"

int32_t check(const uint8_t player[13]){
    for(int32_t i = 0;i < 13;i++){
        for(int32_t j = i + 1;j < 13;j++){
            if(player[i] == player[j]){
                return 0;
            }
        }
        if(player[i] > 52 || player[i] < 1){
            return 0;
        }
    }
    return 1;
}

void print_card(const uint8_t player[13]){
    for(int32_t i = 0;i < 13;i++){
        printf("%2d ",player[i]);
    }
    printf("\n");
}

int32_t sort_card(uint8_t player[13], int32_t ( * compare)( int32_t a, int32_t b )){
    
    int32_t tmp = 0;
    
    for(int32_t i = 0;i < 13;i++){
        for(int32_t j = i + 1;j < 13;j++){
            if(compare(player[i],player[j])){
                tmp = player[i];
                player[i] = player[j];
                player[j] = tmp;
            }
        }
    }
}

int32_t func01(int32_t a,int32_t b){
    int32_t value_a = (a-1) % 13;
    int32_t value_b = (b-1) % 13;
    int32_t suit_a = (a-1) / 13;
    int32_t suit_b = (b-1) / 13;
    int32_t newNum_a = 0;
    int32_t newNum_b = 0;

    if(value_a == 0)value_a = 13;
    if(value_b == 0)value_b = 13;

    suit_a = 3 - suit_a;
    suit_b = 3 - suit_b;

    newNum_a = value_a * 10 + suit_a;
    newNum_b = value_b * 10 + suit_b;

    if(newNum_a < newNum_b){
        return 1;
    }else{
        return 0;
    }
}

int32_t func02(int32_t a,int32_t b){
    int32_t value_a = (a-1) % 13;
    int32_t value_b = (b-1) % 13;
    int32_t suit_a = (a-1) / 13;
    int32_t suit_b = (b-1) / 13;
    int32_t newNum_a = 0;
    int32_t newNum_b = 0;

    if(value_a == 0)value_a = 13;
    if(value_b == 0)value_b = 13;
    if(value_a == 1)value_a = 14;
    if(value_b == 1)value_b = 14;

    newNum_a = value_a * 10 + suit_a;
    newNum_b = value_b * 10 + suit_b;

    if(newNum_a < newNum_b){
        return 1;
    }else{
        return 0;
    }
}

int32_t func03(int32_t a,int32_t b){
    int32_t value_a = (a-1) % 13;
    int32_t value_b = (b-1) % 13;
    int32_t suit_a = (a-1) / 13;
    int32_t suit_b = (b-1) / 13;
    int32_t newNum_a = 0;
    int32_t newNum_b = 0;

    if(value_a == 0)value_a = 13;
    if(value_b == 0)value_b = 13;

    suit_a = 3 - suit_a;
    suit_b = 3 - suit_b;

    newNum_a = suit_a * 13 + value_a + 1;
    newNum_b = suit_b * 13 + value_b + 1;

    if(newNum_a < newNum_b){
        return 1;
    }else{
        return 0;
    }
}