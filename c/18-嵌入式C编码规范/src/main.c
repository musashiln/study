#include <stdint.h>
#include <stdio.h>

static uint8_t clamp_u8(int value)
{
    if (value < 0) return 0u;
    if (value > 255) return 255u;
    return (uint8_t)value;
}

int main(void)
{
    printf("%u\n", (unsigned)clamp_u8(300));
    return 0;
}
