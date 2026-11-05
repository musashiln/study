#include <stdio.h>

int main()
{
    FILE *fw = fopen("test.txt", "w+");
    // 注意: fputs不会自动添加\n
    fputs("lnj\n", fw);
    fputs("it666\n", fw);
    fclose(fw);
    return 0;
}
