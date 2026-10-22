#include <stdio.h>
int main(){
    int a = 10;
    int b = 20;
    // 逻辑与, 前面为假, 不会继续执行后面
    int result = (a == 9) && (++b);
    printf("result = %i\n", result); // 0
    printf("b = %i\n", b); // 20
}
