#include <stdio.h>

int main()
{
    // char占1个字节, char的取值范围 -2^7~2^7
    char num = 129;
    printf("size = %i\n", sizeof(num)); // 1
    printf("num = %i\n", num); // -127
    // short int 占2个字节, short int的取值范围 -2^15~2^15-1
    short int num1 = 32769;// -32767
    printf("size = %i\n", sizeof(num1)); // 2
    printf("num1 = %hi\n", num1);

    // int占4个字节, int的取值范围 -2^31~2^31-1
    int num2 = 12345678901;
    printf("size = %i\n", sizeof(num2)); // 4
    printf("num2 = %i\n", num2);

    // long在32位占4个字节, 在64位占8个字节
    long int num3 = 12345678901;
    printf("size = %i\n", sizeof(num3)); // 4或8
    printf("num3 = %ld\n", num3);

    // long在32位占8个字节, 在64位占8个字节 -2^63~2^63-1
    long long int num4 = 12345678901;
    printf("size = %i\n", sizeof(num4)); // 8
    printf("num4 = %lld\n", num4);
    
    // 由于short/long/long long一般都是用于修饰int, 所以int可以省略
    short num5 = 123;
    printf("num5 = %lld\n", num5);
    long num6 = 123;
    printf("num6 = %lld\n", num6);
    long long num7 = 123;
    printf("num7 = %lld\n", num7);
    return 0;
}
