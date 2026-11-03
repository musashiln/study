#include <stdio.h>
// 第1行中定义了一个带有2个参数的宏average，
#define average(a, b) (a+b)/2

int main ()
  {
  // 第4行其实会被替换成：int a = (10 + 4)/2;，
      int a = average(10, 4);
  // 输出结果为：7是不是感觉这个宏有点像函数呢？
      printf("平均值：%d", a);
     return 0;
 }


