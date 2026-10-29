#include <stdio.h>

int main(void)
{
    int a[5] = {2, 4, 6, 8, 22};
    int *p;
    // p = &(a[0]); 
    p = a;
    printf("%d %d\n",a[0],*p); // 输出结果: 2, 2

    return 0;
}