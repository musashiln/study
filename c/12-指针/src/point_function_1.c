#include <stdio.h>

int sum(int a, int b)
{
    return a + b;
}

int main(void)
{
    int (*p)(int, int) = sum;

    printf("%d\n", sum(3, 5));  // 8：直接调用
    printf("%d\n", p(3, 5));    // 8：通过函数指针调用
    printf("%d\n", (*p)(3, 5)); // 8：另一种写法

    return 0;
}