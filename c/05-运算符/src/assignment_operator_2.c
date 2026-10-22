#include <stdio.h>
int main(){
     // 复合赋值运算符 += -= *= /= %=
     // 将变量中的值取出之后进行对应的操作, 操作完毕之后再重新赋值给变量
     int num1 = 10;
     // num1 = num1 + 1; num1 = 10 + 1; num1 = 11;
     num1 += 1;
     printf("num1 = %i\n", num1); // 11
     int num2 = 10;
     // num2 = num2 - 1; num2 = 10 - 1; num2 = 9;
     num2 -= 1;
     printf("num2 = %i\n", num2); // 9
     int num3 = 10;
     // num3 = num3 * 2; num3 = 10 * 2; num3 = 20;
     num3 *= 2;
     printf("num3 = %i\n", num3); // 20
     int num4 = 10;
     // num4 = num4 / 2; num4 = 10 / 2; num4 = 5;
     num4 /= 2;
     printf("num4 = %i\n", num4); // 5
     int num5 = 10;
     // num5 = num5 % 3; num5 = 10 % 3; num5 = 1;
     num5 %= 3;
     printf("num5 = %i\n", num5); // 1
}
