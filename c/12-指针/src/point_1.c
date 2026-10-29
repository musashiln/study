#include <stdio.h>

int main(void)
{
    int num = 6;
    int num1 = 7;
    char c = 'a';

    printf("int:     %zu bytes\n", sizeof(num));
    printf("char:    %zu bytes\n", sizeof(c));
    printf("pointer: %zu bytes\n", sizeof(&num));
    printf("pointer: %p\n", &num);
    printf("pointer: %p\n", (void *)&num);
    printf("pointer: %p\n", (&num) + 1);
    printf("pointer: %p\n", (void *)&num1);
    return 0;
}