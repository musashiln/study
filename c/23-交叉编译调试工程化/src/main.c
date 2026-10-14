#include <stdio.h>

int main(void)
{
#ifdef DEBUG
    puts("debug build");
#else
    puts("release build");
#endif
    return 0;
}
