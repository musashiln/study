#include <stdio.h>
int main(){
    int number = 10;
    // 赋值运算符优先级是14, 普通运算符优先级是3和4, 所以先计算普通运算符
    // 普通运算符中乘法优先级是3, 加法是4, 所以先计算乘法
    // number += 1 + 25; number += 26; number = number + 26; number = 36;
    number += 1 + 5 * 5;
    printf("number = %i\n", number); // 36
}
