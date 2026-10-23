#include <stdio.h>

// 函数声明
void getMax(int v1, int v2);
int main() {
    getMax(10, 20); // 调用函数
    return 0;
}
// 函数实现
void getMax(int v1, int v2) {
    int max = v1 > v2 ? v1 : v2;
    printf("max = %i\n", max);
}
