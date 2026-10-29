#include <stdio.h>

int main(void)
{
    int num = 6;
    int *p = &num;

    printf("num 的值：%d\n", num);
    printf("num 的地址：%p\n", (void *)&num);

    printf("p 保存的地址：%p\n", (void *)p);
    printf("p 自己的地址：%p\n", (void *)&p);
    printf("通过 p 访问的值：%d\n", *p);

    printf("num 占 %zu 字节\n", sizeof(num));
    printf("p 占 %zu 字节\n", sizeof(p));
    printf("*p 的类型占 %zu 字节\n", sizeof(*p));

    *p = 100;

    printf("修改后 num 的值：%d\n", num);

    return 0;
}