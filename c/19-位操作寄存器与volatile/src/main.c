#include <stdint.h>
#include <stdio.h>

#define BIT(n) (UINT32_C(1) << (n))
#define LED_MASK BIT(3)

static volatile uint32_t fake_port;

static void led_on(void)  { fake_port |= LED_MASK; }
static void led_off(void) { fake_port &= ~LED_MASK; }

int main(void)
{
    led_on();
    printf("port=0x%08x\n", (unsigned)fake_port);
    led_off();
    return 0;
}
