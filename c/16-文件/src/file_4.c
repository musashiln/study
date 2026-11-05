#include <stdio.h>

int main()
{
    FILE *fw = fopen("test.txt", "w+");
    fputc('a', fw);
    fputc('\n', fw);
    fputc('b', fw);
    fclose(fw);
    return 0;
}
