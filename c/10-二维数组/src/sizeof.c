#include <stdio.h>

void test(char cs[2][3])
{
    printf("sizeof(cs) = %zu\n", sizeof(cs));
    printf("sizeof(cs[0]) = %zu\n", sizeof(cs[0]));
}

int main(void)
{
    char data[2][3] = {
        {'a', 'b', 'c'},
        {'d', 'e', 'f'}
    };

    printf("main中数组总大小 = %zu\n", sizeof(data));
    printf("main中行数 = %zu\n", sizeof(data) / sizeof(data[0]));
    printf("main中列数 = %zu\n", sizeof(data[0]) / sizeof(data[0][0]));

    test(data);

    return 0;
}