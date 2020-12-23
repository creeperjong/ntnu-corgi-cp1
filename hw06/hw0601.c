#include <stdio.h>
#include <stdint.h>
#include "int_editor.h"

int main(){
    
    //making each byte can be displayed respectively

    typedef union{
        int64_t i;
        unsigned char c[8];
    }num;

    //Initialize
    
    num input;
    printf("Please enter an integer:");
    scanf("%ld",&input.i);

    //start editing number

    int32_t pos = 0;
    int32_t newValue = 0;

    while(1){
        printf("The integer:%ld\n",input.i);
        print_mem(input.c);
        printf("Please enter the position (1-8, 0: End):");
        scanf("%d",&pos);
        if(pos == 0){
            break;
        }
        printf("Please enter the new value (0-255):");
        scanf("%d",&newValue);

        if(pos > 8 || pos < 0 || newValue > 255 || newValue < 0){
            printf("Invalid Input!\n");
            continue;
        }else{

            //modify the value by changing the value of a specific memory space

            input.c[pos-1] = newValue;
        }
    }
    return 0;
}