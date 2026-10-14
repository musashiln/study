#include <stdio.h>

typedef struct {
    void (*write)(int level);
} Led;

static void fake_led_write(int level)
{
    printf("LED=%d\n", level);
}

int main(void)
{
    Led led = { fake_led_write };
    led.write(1);
    led.write(0);
    return 0;
}
