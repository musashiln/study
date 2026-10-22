#include <stdio.h>
int main(){
    int number;
    int value;
    // 可以输入 数字 空格 数字, 或者 数字 回车 数字
    scanf("%d%d", &number, &value);
    printf("number = %d\n", number);
    printf("value = %d\n", value);
}
