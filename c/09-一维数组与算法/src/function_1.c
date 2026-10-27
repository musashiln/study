#include <stdio.h>
void change(int val)// int val = number
{
    val = 55;
}
int main()
{
    int ages[3] = {1, 5, 8};
    printf("ages[0] = %d", ages[0]);// 1
    change(ages[0]);
    printf("ages[0] = %d", ages[0]);// 1
}
