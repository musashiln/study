#include <stdio.h>

int initialized = 42;
int zero_initialized;
const char message[] = "flash?";

int main(void)
{
    static int local_static;
    int local_auto = 1;
    printf("text=%p data=%p bss=%p stack=%p\n",
           (void *)message, (void *)&initialized,
           (void *)&zero_initialized, (void *)&local_auto);
    (void)local_static;
    return 0;
}
