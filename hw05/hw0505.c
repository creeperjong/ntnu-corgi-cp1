#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>
#include "minesweeper.h"


int main(){

    int32_t width = 0;
    int32_t height = 0;
    int32_t mine = 0;
    int32_t option = 0;
    int32_t posRow = 0;
    int32_t posCol = 0; 
    grid **map;

    printf("Please enter the width (10-16):");
    scanf("%d",&width);
    printf("Please enter the height (10-16):");
    scanf("%d",&height);
    printf("Please enter the mine number (30-90):");
    scanf("%d",&mine);

    if(width < 10 || width > 16 || height < 10 || height > 16 || mine < 30 || mine > 90){
        printf("Invalid Input!\n");
    }else{

        map = mapGenerate(width,height,mine);

        while(1){
            printMap(map,height,width);
            printf("Your Option (1:Open, 2: Flag):");
            scanf("%d",&option);
            printf("Position (row,column):");
            scanf("%d %d",&posRow,&posCol);



            if((option != 1 && option != 2) || posRow > height-1 || posRow < 0 || posCol > width-1 || posCol < 0){
                printf(LIGHT_RED"Invalid Input!\n"RESET);
                continue;
            }else if(option == 1 && map[posRow][posCol].isFlagged == true){
                printf(LIGHT_RED"Invalid Input!\n"RESET);
            }else if(option == 2 && map[posRow][posCol].isOpen == true){
                printf(LIGHT_RED"Invalid Input!\n"RESET);
                continue;
            }else{
                if(option == 1){
                    if(map[posRow][posCol].isMine == true){
                        fori(0,height){
                            forj(0,width){
                                map[i][j].isOpen = true;
                            }
                        }
                        printMap(map,height,width);
                        printf(LIGHT_RED"Boom!\nGame Over! You lose:(\n"RESET);
                        break;
                    }else{
                        map = takeAction(map,height,width,posRow,posCol);
                    }
                }else{
                    if(map[posRow][posCol].isFlagged == false){
                        map[posRow][posCol].isFlagged = true;
                    }else{
                        map[posRow][posCol].isFlagged = false;
                    }
                }
            }



            if(winningJudge(map,height,width)){
                fori(0,height){
                    forj(0,width){
                        if(map[i][j].isOpen == false && map[i][j].isMine == true){
                            map[i][j].isFlagged = true;
                        }
                    }
                }
                printMap(map,height,width);
                printf(LIGHT_YELLOW"　︿︿︿︿︿︿︿︿︿︿︿︿︿︿\n");
                printf("＜　　　　　　　　　　　　　　＞\n");
                printf("＜　You win!Congratulations!　 ＞\n");
                printf("＜　　　　　　　　　　　　　　＞\n");
                printf("　ＶＶＶＶＶＶＶＶＶＶＶＶＶＶ\n"RESET);
                break;
            }
        }
        free(map);
    }
    return 0;
}