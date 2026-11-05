#include <stdio.h>

int main()
{
    FILE *fp = fopen("test.txt", "w+");
    // 注意: fputs写入时遇到\0就会自动终止写入
    fputs("lnj\0it666\n", fp);

    fclose(fp);
    return 0;
}
