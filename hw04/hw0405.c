#include <stdio.h>
#include <stdint.h>
#include "game_system.h"

int main(){
    int32_t guess = 0;
    int32_t guess_arr[4]={0};
    int32_t answer[4]={0};
    int32_t *pointer;
    pointer = generate_num();
    for(int32_t load = 0;load<4;load++){
        answer[load] = *(pointer+load);
    }
    

    printf("Bulls and Cows Game\n");
    /*for(int32_t i = 0;i<4;i++){
        printf("%d",*(pointer+i));
    }
    printf("\n");*/
    for(int32_t round = 1;round>0;round++){

        printf("Round %d >>>\n",round);
        printf("    Your Guess: ");
        scanf("%d",&guess);

        for(int32_t digit = 3;digit>=0;digit--){
            guess_arr[digit] = guess % 10;
            guess /= 10;
        }

        printf("    Response: ");

        if(!check(guess,guess_arr)){
            printf("\e[1;91mInvalid Guess\e[m\n");
        }else{
            if(A_judge(guess_arr,answer) == 4){
                printf("\e[1;92mBingo! Congratulations.\e[m\n");
                break;
            }else{
                printf("%d \e[32mA\e[m %d \e[36mB\e[m\n",A_judge(guess_arr,answer),B_judge(guess_arr,answer));
            }
        }
    }
    return 0;
}