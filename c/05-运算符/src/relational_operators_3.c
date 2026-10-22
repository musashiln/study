#include <stdio.h>
int main(){
    // == 和 != 优先级一样, 所以按照结合性
    // 关系运算符是左结合性, 所以从左至右计算
    // result = 0 != 3; result = 1;
    int result = 10 == 5 != 3;
    printf("result = %i\n", result); // 1
}
