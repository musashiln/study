#include <stdio.h>
int main(){
    int a = 10;
    int b = 5;
    // 先计算 a > b
    // 然后再根据计算结果判定返回a还是b
    // 相当于int max= (a>b) ? a : b;
    int max= a>b ? a : b;
    printf("max = %i\n", max); // 10
}
