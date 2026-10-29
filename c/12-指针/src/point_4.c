#include <stdio.h>

int main(void)
{
    char c = 'a';
    char *cp;
    cp = &c;
    char **cp2;
    cp2 = &cp;
    printf("c = %c", **cp2);

    return 0;
}