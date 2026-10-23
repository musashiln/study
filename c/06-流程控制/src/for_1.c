#include <stdio.h>

int main() {
    // 注意: 在for循环初始化表达式中定义的变量, 只能在for循环后面的{}中访问
// 所以: 如果初始化表达式的值, 不需要在循环之后使用, 那么就用for
// 因为如果初始化表达式的值, 在循环之后就不需要使用了 , 那么用while会导致性能问题
    for (int count = 0; count < 10; count++) {
        printf("发射子弹~哔哔哔哔 %i\n", count);
    }
//     printf("count = %i\n", count);

}