#include <stdio.h>

int main()
{
    // 1.打开一个文件
    FILE *fp = fopen("test.txt", "w+");

    // 2.往文件中写入内容
    for(char ch = 'a'; ch <= 'z'; ch++){
        // 一次写入一个字符
        char res = fputc(ch, fp);
        printf("res = %c\n", res);
    }

    // 3.关闭打开的文件
    fclose(fp);
    return 0;
}
