#include "int_editor.h"

void print_mem(unsigned char* c){
    for(int32_t i = 0;i < 8;i++){
        printf("(%d) 0x%02X ",i+1,c[i]);
    }
    printf("\n");
}
