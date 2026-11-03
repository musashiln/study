// B文件中的代码
#include <stdio.h>
#include "A.c"

int num; // 和A文件中的num共享
int main()
{
    num = 666;
    test(); // test中输出666
    return 0;
}
