#include <stdio.h>
int main(){
    // 10 / 3 商等于3, 余1
    int result = 10 % 3;
    printf("%i\n", result); // 1

    // 左边小于右边, 那么结果就是左边
    result = 2 % 10;
    printf("%i\n", result); // 2

    // 被除数是正数结果就是正数,被除数是负数结果就是负数
    result = 10 % 3;
    printf("%i\n", result); // 1
    result = -10 % 3;
    printf("%i\n", result); // -1
    result = 10 % -3;
    printf("%i\n", result); // 1
}
