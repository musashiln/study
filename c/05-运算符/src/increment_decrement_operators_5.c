#include <stdio.h>
int main(){
    int number = 10;
    // --在前, 先自减, 再参与表达式运算
    // 表达式运算时为: 9 + 3;
    int result = --number + 3;
    printf("result = %i\n", result); // 12
    printf("number = %i\n", number); // 9
}
