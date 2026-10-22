#include <stdio.h>

int main() {
    //强制类型转换
    //将double转换为int(显式转换)
    int a = (int)10.5;
    printf("a = %d\n", a);

    //算数转换
    // 当前表达式用1.0占用8个字节, 2占用4个字节
    // 所以会先将整数类型2转换为double类型之后再计算
    double b = 1.0 / 2;
    printf("b = %lf\n", b);

    //赋值转换
    // 赋值时左边是什么类型,就会自动将右边转换为什么类型再保存
    a = 10.6;
    printf("a = %d\n", a);


}