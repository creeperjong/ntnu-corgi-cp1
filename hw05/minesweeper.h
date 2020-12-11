#pragma once

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define fori(x,y) for(int32_t i = x;i < y;i++)
#define forj(x,y) for(int32_t j = x;j < y;j++)
#define form(x,y) for(int32_t m = x;m <= y;m++)
#define forn(x,y) for(int32_t n = x;n <= y;n++)

#define FLAG_COLOR "\e[1;106m"
#define MINE_COLOR "\e[1;101m"
#define BLACK "\e[30m"
#define RED "\e[31m"
#define GREEN "\e[32m"
#define YELLOW "\e[33m"
#define BLUE "\e[34m"
#define PINK "\e[35m"
#define CYAN "\e[36m"
#define LIGHT_RED "\e[1;31m"
#define LIGHT_YELLOW "\e[1;33m"
#define RESET "\e[m"

typedef struct grid{
    bool isOpen;
    bool isMine;
    bool isFlagged;
    int32_t nearbyMine;
}grid;

grid **mapGenerate(int32_t width,int32_t height,int32_t mine);

void printMap(grid **map,int32_t height,int32_t width);

grid **takeAction(grid **map,int32_t height,int32_t width,int32_t row,int32_t col);

bool winningJudge(grid **map,int32_t height,int32_t width);