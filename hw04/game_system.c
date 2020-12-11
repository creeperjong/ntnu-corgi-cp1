#include "game_system.h"

int32_t* generate_num(void){
    static int32_t ans[4]={0};
    int32_t isAccepted = 0;
    srand(time(0));
    for(int32_t generate = 0;generate<4;generate++){
        ans[generate] = rand() % 10;
    }
    for(int32_t check = 0;check<4;check++){
        while(1){
            for(int32_t index = 0;index<4;index++){
                if(check != index){
                    if(ans[check] == ans[index]){
                        ans[check] = rand() % 10;
                        break;
                    }
                }
                if(index == 3){
                    isAccepted = 1;
                }
            }
            if(isAccepted){
                isAccepted = 0;
                break;
            }
        }
    }
    return ans;
}

int32_t check(int32_t input,int32_t *input_arr){
    if(input < 0 || input > 9999){
        return 0;
    }else{
        for(int32_t base = 0;base<4;base++){
            for(int32_t seek = base+1;seek<4;seek++){
                if(*(input_arr+base) == *(input_arr+seek)){
                    return 0;
                }
            }
        }
        return 1;
    }
}

int32_t A_judge(int32_t *input_arr,int32_t *ans){
    int32_t count = 0;
    for(int32_t index = 0;index<4;index++){
        if(*(input_arr+index) == *(ans+index)){
            count++;
        }
    }
    return count;
}

int32_t B_judge(int32_t *input_arr,int32_t *ans){
    int32_t count = 0;
    for(int32_t i = 0;i<4;i++){
        for(int32_t j = 0;j<4;j++){
            if(*(input_arr+i) == *(ans+j) && i!=j){
                count++;
            }
        }
    }
    return count;
}