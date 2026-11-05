
#include <stdio.h>

int main()
{
    FILE *fp = fopen("test.txt", "w+");
    fputs("123456789", fp);
    // 将文件指针移动到文件结尾, 并且偏移0个单位
    fseek(fp, 0, SEEK_END);
    int len = ftell(fp); // 计算文件长度
    printf("len = %i\n", len);
    fclose(fp);
    return 0;
}
