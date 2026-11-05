#include <stdio.h>

int main()
{
    FILE *fp = fopen("test.txt", "w+");
    // 注意: fputs不会自动添加\n
    fputs("12345678910\n", fp);
    fputs("12345678910\n", fp);
    fputs("12345678910", fp);

    // 将FILE结构体中的读写指针重新移动到最前面
    // 注意: FILE结构体中读写指针每读或写一个字符后都会往后移动
    rewind(fp);
    char str[1024];
    // 每次从fp中读取1024个字符, 存入到str中
    // 读取到文件末尾自动结束
    while(fgets(str, 1024, fp) && !feof(fp)){
        printf("str = %s", str);
    }
    fclose(fp);
    return 0;
}
