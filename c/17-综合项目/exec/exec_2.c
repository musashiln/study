#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int *nums;
    nums = (int *)malloc(sizeof(int) * 2);
    nums[0] = 3;
    nums[1] = 5;
    int capacity = 2;
    int n = 2;

    printf("一个指针：%zu 字节\n", sizeof nums);
    printf("一个元素：%zu 字节\n", sizeof *nums);
    printf("扩容后的总大小：%zu 字节\n", 4 * sizeof *nums);

    int new_capacity = 4;
    int *temp = realloc(nums, new_capacity * sizeof *nums);

    if (temp == NULL) {
        printf("扩容失败\n");
        free(nums);
        return 1;
    }

    nums = temp;
    capacity = new_capacity;

    nums[n] = 8;
    n++;
    return 0;
}