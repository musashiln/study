#include <stdio.h>

typedef int (*CompareFn)(int, int);

static int ascending(int a, int b)
{
    return a < b;
}

static void report(CompareFn compare)
{
    printf("compare(2, 3) = %d\n", compare(2, 3));
}

int main(void)
{
    report(ascending);
    return 0;
}
