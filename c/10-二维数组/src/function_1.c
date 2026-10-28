#include <stdio.h>

// 和一位数组一样, 只看形参是基本类型还是数组类型
// 如果是数组类型在函数中修改形参会影响实参
void change(char ch[][3]){
    ch[0][0] = 'n';
}
int main()
{
    char cs[2][3] = {
        {'a', 'b', 'c'},
        {'d', 'e', 'f'}
    };
    printf("cs[0][0] = %c\n", cs[0][0]); // a
    change(cs);
    printf("cs[0][0] = %c\n", cs[0][0]); // n
    return 0;
}
