#include <stdio.h>
#include <stdint.h>

int main(){
    
    typedef union{
        int64_t i;
        char c[8];
    }num;

    //Initialize
    
    num input;
    printf("Please enter an integer:");
    scanf("%d",&input.i);
    printf("The integer:%d\n",input.i);

    

}