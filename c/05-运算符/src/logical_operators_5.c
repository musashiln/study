#include <stdio.h>
int main(){
    int a = 10;
    int b = 20;
    // 逻辑或, 前面为真, 不会继续执行后面
    int result = (a == 10) || (++b);
    printf("result = %i\n", result); // 1
    printf("b = %i\n", b); // 20

    result = 3>5 || 2<4 && 6<1;
    printf("result = %i\n", result); //0
}
