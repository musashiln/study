#include <stdio.h>

int main()
{
    // 1.打开一个文件
    FILE *fp = fopen("test.txt", "r+");

    // 2.从文件中读取内容
    char res = EOF;
    // 注意: 由于只有先读了才会修改标志位,
    // 所以通过feof判断是否到达文件末尾, 一定要先读再判断, 不能先判断再读
    while((res = fgetc(fp)) && (!feof(fp))){
        printf("res = %c\n", res);
    }

    // 3.关闭打开的文件
    fclose(fp);
    return 0;
}
