#include <stdio.h>

int main()
{
    char *str = "123456789";
    FILE *fp = fopen("test.txt", "w+");
    long cp = ftell(fp);
    printf("cp = %li\n", cp); // 0
    // 写入一个字节
    fputc(str[0], fp);
    cp = ftell(fp);
    printf("cp = %li\n", cp); // 1
    // 新指向一个流的开头
    rewind(fp);
    cp = ftell(fp);
    printf("cp = %li\n", cp); // 0
    fclose(fp);
    return 0;
}
