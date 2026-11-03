#include <stdio.h>
  // 下面定义一个宏D(a)，作用是返回a的2倍数值：
// #define D(a) 2*a
#define D(a) ((2)*(a))
  // 如果定义宏的时候不用小括号括住参数

int main ()
{
// 将被替换成int b = 2*3+4;，输出结果10，如果定义宏的时候用小括号括住参数，把上面的第3行改成：#define D(a) 2*(a)，注意右边的a是有括号的，第7行将被替换成int b = 2*(3+4);，输出结果14

    int b = D(3+4);
    printf("%d", b);
    return 0;
}
