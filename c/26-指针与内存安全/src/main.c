#include <stdio.h>
#include <stdlib.h>

static int *make_value(int value)
{
    int *p = malloc(sizeof *p);
    if (p != NULL) *p = value;
    return p;
}

int main(void)
{
    int *value = make_value(42);
    if (value == NULL) return 1;
    printf("%d\n", *value);
    free(value);
    value = NULL;
    return 0;
}
