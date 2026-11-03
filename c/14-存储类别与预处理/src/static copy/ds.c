#include <stdio.h>
#include "ds.h"

static int num;  // 自动初始化为 0，只在当前源文件内部使用

void test(void)
{
    printf("ds.c num = %d\n", num);
}