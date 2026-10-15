#include <assert.h>
#include <stdio.h>

static int divide(int a, int b)
{
    assert(b != 0);
    return a / b;
}

int main(void)
{
    assert(divide(6, 2) == 3);
    puts("tests passed");
    return 0;
}
