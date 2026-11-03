#include "counter.h"

int count = 0;          // 在一个 .c 文件中定义变量

void increment(void)
{
    count++;
}