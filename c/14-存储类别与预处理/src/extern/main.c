#include <stdio.h>
#include "counter.h"

int main(void)
{
    increment();
    increment();

    printf("%d\n", count);  // 输出 2
    return 0;
}