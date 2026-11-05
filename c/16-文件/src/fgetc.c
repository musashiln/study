#include <stdio.h>

int main()
{
    // 1.打开一个文件
    FILE *fp = fopen("ascii.txt", "r+");

    // 2.从文件中读取内容
    char res = EOF;
    while((res = fgetc(fp)) != EOF){
        printf("res = %c\n", res);
    }

    // 3.关闭打开的文件
    fclose(fp);
    return 0;
}
