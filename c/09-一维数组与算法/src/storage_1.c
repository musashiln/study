#include <stdio.h>
int main()
{
    int num = 9;
    char cs[] = {'l','n','j'};
    printf("cs = %p\n", &cs);       // cs = 0060FEA9
    printf("cs[0] = %p\n", &cs[0]); // cs[0] = 0060FEA9
    printf("cs[1] = %p\n", &cs[1]); // cs[1] = 0060FEAA
    printf("cs[2] = %p\n", &cs[2]); // cs[2] = 0060FEAB

    int nums[] = {2, 6};
    printf("nums = %p\n", &nums);      // nums = 0060FEA0
    printf("nums[0] = %p\n", &nums[0]);// nums[0] = 0060FEA0
    printf("nums[1] = %p\n", &nums[1]);// nums[1] = 0060FEA4
    
    return 0;
}
