#include <stdio.h>
void change2(int array[3])// int array = 0ffd1
{
    array[0] = 88;
    //当数组名作为函数参数时, 因为自动转换为了指针类型，所以在函数中无法动态计算除数组的元素个数
    printf("printArray size = %lu\n", sizeof(array)); // 8
    int length = sizeof(array)/ sizeof(int); // 2
    printf("length = %d\n", length);
}
int main()
{
    int ages[3] = {1, 5, 8};
    printf("ages[0] = %d\n", ages[0]);// 1
    change2(ages);
    printf("ages[0] = %d\n", ages[0]);// 88
}
