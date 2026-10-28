#include <stdio.h>

int main(void)
{
    int a[2] = {10, 20};

    printf("&a[0] = %p\n", (void *)&a[0]);
    printf("&a[1] = %p\n", (void *)&a[1]);

    int x = 0x12345678;
    unsigned char *p = (unsigned char *)&x;

    for (int i = 0; i < (int)sizeof(x); i++) {
        printf("第%d个字节：0x%02x\n", i, p[i]);
    }

    return 0;
}