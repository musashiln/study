// 函数指针有什么用:
// 它能让同一个调用位置，根据指向执行不同函数。
#include <stdio.h>

int sum(int a, int b)
{
    return a + b;
}

int sub(int a, int b)
{
    return a - b;
}

int main(void)
{
    int (*p)(int, int) = sum;
    printf("%d\n", p(8, 3));  // 11：调用 sum

    p = sub;
    printf("%d\n", p(8, 3));  // 5：调用 sub

    return 0;
}