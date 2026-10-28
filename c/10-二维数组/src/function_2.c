#include <stdio.h>

// void test1(char cs[2][]) // 错误写法
// {
//     printf("我被执行了\n");
// }

void test2(char cs[2][3]) // 正确写法
{
    printf("我被执行了\n");
}

void test3(char cs[][3]) // 正确写法
{
    printf("我被执行了\n");
}


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
