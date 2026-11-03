#include <stdio.h>

int main()
{
    extern int num; // 声明我们有名称叫做num变量
    num = 998; // 使用时已经有对应的存储空间
    printf("num = %i\n", num);
    return 0;
}
int num; // 全局变量, 程序启动就会分配存储空间
