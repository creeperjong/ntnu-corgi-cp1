#include "minesweeper.h"


grid **mapGenerate(int32_t width,int32_t height,int32_t mine){
    srand(time(NULL));

    //Initialize

    grid **map = (grid**) malloc (height * sizeof(grid*));
    fori(0,height){
        map[i] = (grid*) malloc (width * sizeof(grid));
    }
    fori(0,height){
        forj(0,width){
            map[i][j].isOpen = false;
            map[i][j].isMine = false;
            map[i][j].isFlagged = false;
            map[i][j].nearbyMine = 0;
        }
    }

    //spawn mines

    int32_t mineGrid = 0;
    int32_t mineCount = 0;

    while(1){
        mineGrid = rand() % (height * width);
        if(map[mineGrid / width][mineGrid % width].isMine == false){
            map[mineGrid / width][mineGrid % width].isMine = true;
            mineCount++;
        }else{
            continue;
        }
        if(mineCount == mine){
            break;
        }
    }

    //set mine number nearby

    int32_t numberCount = 0;

    fori(0,height){
        forj(0,width){
            form(-1,1){
                forn(-1,1){
                    if(i + m > height - 1 || i + m < 0 || j + n > width - 1 || j + n < 0){
                        continue;
                    }else{
                        if(map[i+m][j+n].isMine == true){
                            numberCount++;
                        }
                    }
                }
            }
            map[i][j].nearbyMine = numberCount;
            numberCount = 0;
        }
    }
    return map;
}

void printMap(grid **map,int32_t height,int32_t width){
    printf("\n   ");
    fori(0,width){
        if(i<10){
            printf("0%d ",i);
        }else{
            printf("%d ",i);
        }
    }
    printf("\n---");
    fori(0,width){
        printf("---");
    }
    printf("\n");
    fori(0,height){
        if(i<10){
            printf("0%d|",i);
        }else{
            printf("%d|",i);
        }
        forj(0,width){
            if(map[i][j].isFlagged == true){
                printf(FLAG_COLOR" F "RESET);
            }else if(map[i][j].isOpen == false){
                printf(" * ");
            }else if(map[i][j].isMine == true){
                printf(MINE_COLOR" X "RESET);
            }else if(map[i][j].nearbyMine == 0){
                printf("   ");
            }else{
                if(map[i][j].nearbyMine == 1){
                    printf(BLUE" 1 "RESET);
                }else if(map[i][j].nearbyMine == 2){
                    printf(GREEN" 2 "RESET);
                }else if(map[i][j].nearbyMine == 3){
                    printf(RED" 3 "RESET);
                }else if(map[i][j].nearbyMine == 4){
                    printf(BLUE" 4 "RESET);
                }else if(map[i][j].nearbyMine == 5){
                    printf(RED" 5 "RESET);
                }else if(map[i][j].nearbyMine == 6){
                    printf(CYAN" 6 "RESET);
                }else if(map[i][j].nearbyMine == 7){
                    printf(PINK" 7 "RESET);
                }else if(map[i][j].nearbyMine == 8){
                    printf(PINK" 8 "RESET);
                }
            }
        }
        printf("\n");
    }
}

grid **takeAction(grid **map,int32_t height,int32_t width,int32_t row,int32_t col){
    map[row][col].isOpen = true;
    
    //check grids all around

    if(map[row][col].nearbyMine == 0){
        form(-1,1){
            forn(-1,1){
                if(row + m > height - 1 || row + m < 0 || col + n > width - 1 || col + n < 0){
                    continue;
                }else{
                    if(map[row + m][col + n].isOpen == false){
                        map = takeAction(map,height,width,row+m,col+n);
                    }
                }
            }
        }
    }
    return map;
}

bool winningJudge(grid **map,int32_t height,int32_t width){
    fori(0,height){
        forj(0,width){
            if(map[i][j].isMine == false && map[i][j].isOpen == false){
                return false;
            }    
        }
    }
    return true;
}