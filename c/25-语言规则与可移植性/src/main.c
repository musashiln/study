#include <limits.h>
#include <stdio.h>
#include <stdint.h>

int main(void)
{
    uint8_t byte = 0x01u;
    printf("CHAR_BIT = %d\n", CHAR_BIT);
    printf("uint8_t size = %zu\n", sizeof byte);
    printf("value = %u\n", (unsigned)byte);
    return 0;
}
