#include <stdio.h>
int main(){
    // == 优先级 小于 >, 所以先计算>
    // result = 10 == 1; result = 0;
    int result = 10 == 5 > 3;
    printf("result = %i\n", result); // 0
}
