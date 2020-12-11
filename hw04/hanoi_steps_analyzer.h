#ifndef _HANOI_STEPS_ANALYZER_H_
#define _HANOI_STEPS_ANALYZER_H_

#include <stdio.h>
#include <stdint.h>

void hanoi_steps_recrusive(int32_t spare_disk_num,int32_t source,int32_t target,int32_t spare);

void hanoi_steps_iterative(int32_t spare_disk_num);
#endif