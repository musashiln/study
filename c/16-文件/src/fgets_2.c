#include <stdio.h>
int main()
{
    FILE *fp = fopen("test.txt", "w+");
    // 注意: fputs不会自动添加\n
    fputs("lnj\n", fp);
    fputs("it666\n", fp);

    // 将FILE结构体中的读写指针重新移动到最前面
    // 注意: FILE结构体中读写指针每读或写一个字符后都会往后移动
    rewind(fp);
    char str[1024];
    // 从fp中读取1024个字符, 存入到str中
    // 但是读到第4个就是\n了, 函数会自动停止读取
    // 注意点: \n会被读取进来
    fgets(str, 1024, fp);

    printf("str = %s", str); // lnj
    fclose(fp);
    return 0;
}
