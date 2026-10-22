#include <stdio.h>
int main(){
    int number;
    // 用户必须输入number = 数字  , 否则会得到一个意外的值
    scanf("number = %d", &number);
    printf("number = %d\n", number);
}
