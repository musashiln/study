#include <stdio.h>
int main(){
    int number = 10;
    // --在后, 先参与表达式运算, 再自减
    // 表达式运算时为: 10 + 3;
    int result = number-- + 3;
    printf("result = %i\n", result); // 13
    printf("number = %i\n", number); // 9
}

