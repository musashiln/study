#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    /*
    // 1.申请3块4个字节存储空间
    int *p = (int *)malloc(sizeof(int) * 3);
    // 2.使用申请好的3块存储空间
    p[0] = 1;
    p[1] = 3;
    p[2] = 5;
    printf("p[0] = %i\n", p[0]);
    printf("p[1] = %i\n", p[1]);
    printf("p[2] = %i\n", p[2]);
    // 3.释放空间
    free(p);
    */

    // 1.申请3块4个字节存储空间
    int *p = calloc(3, sizeof(int));
    // 2.使用申请好的3块存储空间
    p[0] = 1;
    p[1] = 3;
    p[2] = 5;
    printf("p[0] = %i\n", p[0]);
    printf("p[1] = %i\n", p[1]);
    printf("p[2] = %i\n", p[2]);
    // 3.释放空间
    free(p);

    return 0;
}
