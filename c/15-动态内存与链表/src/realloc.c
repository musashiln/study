#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // 1.申请4个字节存储空间
    int *p = malloc(sizeof(int));
    printf("p = %p\n", p);
    // 如果能在传入存储空间地址后面扩容, 返回传入存储空间地址
    // 如果不能在传入存储空间地址后面扩容, 返回一个新的存储空间地址
    p = realloc(p, sizeof(int) * 2);
    printf("p = %p\n", p);
    // 2.使用申请好的空间
    *p = 666;
    printf("*p = %i\n",  *p);
    // 3.释放空间
    free(p);

    return 0;
}
