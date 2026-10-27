#include <stdio.h>

void total(int num , int base, int offset);

void toBinary(int num)
{
    total(num, 1, 1);
}
void toOct(int num)
{
    total(num, 7, 3);
}
void toHex(int num)
{
    total(num, 15, 4);
}

void total(int num , int base, int offset)
{
    //    1.定义表用于查询结果
    char cs[] = {
        '0', '1', '2', '3', '4', '5',
        '6', '7', '8', '9', 'a', 'b',
        'c', 'd', 'e', 'f'
    };
    //    2.定义保存结果的数组
    char rs[32];
    //    计算最大的角标位置
    int length = sizeof(rs)/sizeof(char);
    int pos = length;//8

    while (num != 0) {
        int index = num & base;
        rs[--pos] = cs[index];
        num = num >> offset;
    }

    for (int i = pos; i < length; i++) {
        printf("%c", rs[i]);
    }
    printf("\n");
}
int main()
{
    toBinary(9);
    return 0;
}
