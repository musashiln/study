#include <stdio.h>

static void platform_led_write(int on)
{
    printf("[GPIO] LED=%s\n", on ? "ON" : "OFF");
}

static void platform_uart_write(const char *text)
{
    printf("[UART] %s\n", text);
}

int main(void)
{
    platform_uart_write("boot");
    platform_led_write(1);
    platform_led_write(0);
    return 0;
}
