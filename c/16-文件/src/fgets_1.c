#include <stdio.h>

int main()
{
    FILE *fp = fopen("test.txt", "w+");
    // 注意: fputs不会自动添加\n
    fputs("it666\n", fp);

    // 将FILE结构体中的读写指针重新移动到最前面
    // 注意: FILE结构体中读写指针每读或写一个字符后都会往后移动
    rewind(fp);
    char str[1024];
    // 从fp中读取4个字符, 存入到str中
    // 最多只能读取N-1个字符, 会在最后自动添加\0
    fgets(str, 4, fp);

    printf("str = %s", str); // it6
    fclose(fp);
    return 0;
}
