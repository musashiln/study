#include <stdio.h>
int main(){
    int number = 10;
    // ++在后, 先参与表达式运算, 再自增
    // 表达式运算时为: 3 + 10;
    int result = 3 + number++;
    printf("result = %i\n", result); // 13
    printf("number = %i\n", number); // 11
}
