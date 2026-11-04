#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    /*
     * malloc
     * 第一个参数: 需要申请多少个字节空间
     * 返回值类型: void *
     */ 
    int *p = (int *)malloc(sizeof(int));
    printf("p = %i\n", *p); // 保存垃圾数据
    /*
     * 第一个参数: 需要初始化的内存地址
     * 第二个初始: 需要初始化的值
     * 第三个参数: 需要初始化对少个字节
     */ 
    memset(p, 0, sizeof(int)); // 对申请的内存空间进行初始化
    printf("p = %i\n", *p); // 初始化为0
    return 0;
}
