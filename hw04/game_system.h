#ifndef _GAME_SYSTEM_H_
#define _GAME_SYSTEM_H_

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int32_t* generate_num(void);

int32_t check(int32_t input,int32_t *input_arr);

int32_t A_judge(int32_t *input_arr,int32_t *ans);

int32_t B_judge(int32_t *input_arr,int32_t *ans);

#endif