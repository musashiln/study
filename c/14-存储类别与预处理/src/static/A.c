#include <stdio.h>

// A文件中的代码
int num; // 和B文件中的num共享
void test(){
    printf("A.c中的 num = %i\n", num);
}

