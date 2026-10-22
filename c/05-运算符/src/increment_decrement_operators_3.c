#include <stdio.h>
int main(){
    int number = 10;
    // ++在前, 先自增, 再参与表达式运算
    // 表达式运算时为: 3 + 11;
    int result = 3 + ++number;
    printf("result = %i\n", result); // 14
    printf("number = %i\n", number); // 11
}
