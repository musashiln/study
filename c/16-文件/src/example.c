#include <stdio.h>

int main()
{
    /*
     * 以文本形式存储
     * 会将每个字符先转换为对应的ASCII,
     * 然后再将ASCII码的二进制存储到计算机中
     */
    int num = 666;
    FILE *fa = fopen("ascii.txt", "w");
    fprintf(fa, "%d", num);
    fclose(fa);

    /*
     * 以二进制形式存储
     * 会将666的二进制直接存储到文件中
     */
    FILE *fb = fopen("bin.txt", "w");
    fwrite(&num, 4, 1, fb);
    fclose(fb);

    return 0;
}
