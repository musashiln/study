#include <stdio.h>
#include "ds.h"

int num;  // 与 ds.c 中的 num 是两个独立变量

int main(void)
{
    num = 666;

    printf("main.c num = %d\n", num);
    test();

    return 0;
}