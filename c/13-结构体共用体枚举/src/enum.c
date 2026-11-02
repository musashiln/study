#include <stdio.h>

/*
C语言编译器会将枚举元素(spring、summer等)作为整型常量处理，称为枚举常量。
枚举元素的值取决于定义时各枚举元素排列的先后顺序。默认情况下，第一个枚举元素的值为0，第二个为1，依次顺序加1。
也可以在定义枚举类型时改变枚举元素的值
*/

enum Season{
    Spring,
    Summer,
    Autumn,
    Winter
} s;

enum Season1 {
    Spring = 9,
    Summer,
    Autumn,
    Winter
};
// 也就是说spring的值为9，summer的值为10，autumn的值为11，winter的值为12


int main(){

    s = Spring; // 等价于 s = 0;
    s = 3; // 等价于 s = winter;
    printf("%d", s);
}