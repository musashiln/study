#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // 1.申请4个字节存储空间
    int *p = (int *)malloc(sizeof(int));
    // 2.初始化4个字节存储空间为0
    memset(p, 0, sizeof(int));
    // 3.释放申请的存储空间
    free(p);
    return 0;
}
