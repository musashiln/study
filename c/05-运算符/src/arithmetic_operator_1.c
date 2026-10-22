#include <stdio.h>
int main(){
    int a = 10;
    int b = 5;
    // 加法
    int result = a + b;
    printf("%i\n", result); // 15
    // 减法
    result = a - b;
    printf("%i\n", result); // 5
    // 乘法
    result = a * b;
    printf("%i\n", result); // 50
    // 除法
    result = a / b;
    printf("%i\n", result); // 2
    
    // 算术运算符的结合性和优先级
    // 结合性: 左结合性, 从左至右
    int c = 50;
    result = a + b + c; // 15 + c;  65;
    printf("%i\n", result);
    
    // 优先级: * / % 大于 + -
    result = a + b * c; // a + 250; 260;
    printf("%i\n", result);
}
