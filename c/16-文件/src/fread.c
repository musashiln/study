#include <stdio.h>

int main()
{
    // test.txt中存放的是"lnj\0it666"
    FILE *fr = fopen("test.txt", "rb+");
    char buf[1024] = {0};
    // fread函数读取成功返回读取到的字节数, 读取失败返回0
    /*
     * 第一个参数: 存储读取到数据的容器
     * 第二个参数: 每次读取多少个字节
     * 第三个参数: 需要读取多少次
     * 第四个参数: 已打开文件结构体指针
     */ 
    int n = fread(buf, 1, 1024, fr);
    printf("%i\n", n);
    for(int i = 0; i < n; i++){
        printf("%c", buf[i]);
    }
    fclose(fr);
    return 0;
}
