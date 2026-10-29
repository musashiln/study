#include <stdio.h>

int main(void)
{
    int a = 5;
    int *p = &a;
    int b = 10;
    p = &b; // 修改指针指向

    return 0;
}