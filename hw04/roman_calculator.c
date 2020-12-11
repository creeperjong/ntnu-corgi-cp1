#include "roman_calculator.h"

char* roman(int32_t arabic){
    static char result[21];
    int32_t digit[4];
    int32_t digit_index = 0;
    for(int i = 3;i>=0;i--){
        digit[i] = arabic % 10;
        arabic /= 10;
    }

    //千位數
    
    if(digit[0]==1){
        result[digit_index] = 'M';
        digit_index += 1;
    }else if(digit[0]==2){
        result[digit_index] = 'M';
        result[digit_index+1] = 'M';
        digit_index += 2;
    }else if(digit[0]==3){
        result[digit_index] = 'M';
        result[digit_index+1] = 'M';
        result[digit_index+2] = 'M';
        digit_index += 3;
    }

    //百位數

    if(digit[1]==1){
        result[digit_index] = 'C';
        digit_index += 1;
    }else if(digit[1]==2){
        result[digit_index] = 'C';
        result[digit_index+1] = 'C';
        digit_index += 2;
    }else if(digit[1]==3){
        result[digit_index] = 'C';
        result[digit_index+1] = 'C';
        result[digit_index+2] = 'C';
        digit_index += 3;
    }else if(digit[1]==4){
        result[digit_index] = 'C';
        result[digit_index+1] = 'D';
        digit_index += 2;
    }else if(digit[1]==5){
        result[digit_index] = 'D';
        digit_index += 1;
    }else if(digit[1]==6){
        result[digit_index] = 'D';
        result[digit_index+1] = 'C';
        digit_index += 2;
    }else if(digit[1]==7){
        result[digit_index] = 'D';
        result[digit_index+1] = 'C';
        result[digit_index+2] = 'C';
        digit_index += 3;
    }else if(digit[1]==8){
        result[digit_index] = 'D';
        result[digit_index+1] = 'C';
        result[digit_index+2] = 'C';
        result[digit_index+3] = 'C';
        digit_index += 4;
    }else if(digit[1]==9){
        result[digit_index] = 'C';
        result[digit_index+1] = 'M';
        digit_index += 2;
    }
    
    //十位數

    if(digit[2]==1){
        result[digit_index] = 'X';
        digit_index += 1;
    }else if(digit[2]==2){
        result[digit_index] = 'X';
        result[digit_index+1] = 'X';
        digit_index += 2;
    }else if(digit[2]==3){
        result[digit_index] = 'X';
        result[digit_index+1] = 'X';
        result[digit_index+2] = 'X';
        digit_index += 3;
    }else if(digit[2]==4){
        result[digit_index] = 'X';
        result[digit_index+1] = 'L';
        digit_index += 2;
    }else if(digit[2]==5){
        result[digit_index] = 'L';
        digit_index += 1;
    }else if(digit[2]==6){
        result[digit_index] = 'L';
        result[digit_index+1] = 'X';
        digit_index += 2;
    }else if(digit[2]==7){
        result[digit_index] = 'L';
        result[digit_index+1] = 'X';
        result[digit_index+2] = 'X';
        digit_index += 3;
    }else if(digit[2]==8){
        result[digit_index] = 'L';
        result[digit_index+1] = 'X';
        result[digit_index+2] = 'X';
        result[digit_index+3] = 'X';
        digit_index += 4;
    }else if(digit[2]==9){
        result[digit_index] = 'X';
        result[digit_index+1] = 'C';
        digit_index += 2;
    }

    //個位數

    if(digit[3]==1){
        result[digit_index] = 'I';
        digit_index += 1;
    }else if(digit[3]==2){
        result[digit_index] = 'I';
        result[digit_index+1] = 'I';
        digit_index += 2;
    }else if(digit[3]==3){
        result[digit_index] = 'I';
        result[digit_index+1] = 'I';
        result[digit_index+2] = 'I';
        digit_index += 3;
    }else if(digit[3]==4){
        result[digit_index] = 'I';
        result[digit_index+1] = 'V';
        digit_index += 2;
    }else if(digit[3]==5){
        result[digit_index] = 'V';
        digit_index += 1;
    }else if(digit[3]==6){
        result[digit_index] = 'V';
        result[digit_index+1] = 'I';
        digit_index += 2;
    }else if(digit[3]==7){
        result[digit_index] = 'V';
        result[digit_index+1] = 'I';
        result[digit_index+2] = 'I';
        digit_index += 3;
    }else if(digit[3]==8){
        result[digit_index] = 'V';
        result[digit_index+1] = 'I';
        result[digit_index+2] = 'I';
        result[digit_index+3] = 'I';
        digit_index += 4;
    }else if(digit[3]==9){
        result[digit_index] = 'I';
        result[digit_index+1] = 'X';
        digit_index += 2;
    }

    return result;
}