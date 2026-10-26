#include <stdio.h>

int main()
{
    // 1.默认情况下所有类型都是由符号的
    int num1 = 9;
    int num2 = -9;
    int num3 = 0;
    printf("num1 = %i\n", num1);
    printf("num2 = %i\n", num2);
    printf("num3 = %i\n", num3);

    // 2.signed用于明确说明, 当前保存的数据可以是有符号的, 一般情况下很少使用
    signed int num4 = 9;
    signed int num5 = -9;
    signed int num6 = 0;
    printf("num4 = %i\n", num4);
    printf("num5 = %i\n", num5);
    printf("num6 = %i\n", num6);

    // signed也可以省略数据类型, 但是不推荐这样编写
    signed num7 = 9;
    printf("num7 = %i\n", num7);
   

    // 3.unsigned用于明确说明, 当前不能保存有符号的值, 只能保存0和正数
    // 应用场景: 保存银行存款,学生分数等不能是负数的情况
    unsigned int num8 = -9;
    unsigned int num9 = 0;
    unsigned int num10 = 9;
    // 注意: 不看怎么存只看怎么取
    printf("num8 = %u\n", num8);
    printf("num9 = %u\n", num9);
    printf("num10 = %u\n", num10);
    return 0;
}
