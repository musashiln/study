#include <stdio.h>
#include <string.h>

int main()
{
    FILE *fp = fopen("test.txt", "wb+");
    // 注意: fwrite不会关心写入数据的格式
    char *str = "lnj\0it666";
     /*
     * 第一个参数: 被写入数据指针
     * 第二个参数: 每次写入多少个字节
     * 第三个参数: 需要写入多少次
     * 第四个参数: 已打开文件结构体指针
     */
    fwrite((void *)str, 9, 1, fp);

    fclose(fp);
    return 0;
}
