#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *end = NULL;
    errno = 0;
    long value = strtol("1234", &end, 10);
    if (errno != 0 || end == NULL || *end != '\0') {
        perror("strtol");
        return 1;
    }
    printf("%ld\n", value);
    return 0;
}
