#include <stdio.h>

int is_sorted(const int nums[], size_t n)
{
    if (n == 0 || n == 1) {
        return 1;
    }
    /* 有序返回 1，否则返回 0 */
    for (size_t i = 0; i + 1 < n; i++) {
        if (nums[i] > nums[i + 1]) {
            return 0;
        }
    }
    return 1;
}

void bubble_sort(int nums[], size_t n) {
    if (n == 0) {
        return;
    }
    for (size_t j = 0; j < n - 1; j++) {
        int swapped = 0;
        for (size_t i = 0; i + 1 < n - j; i++) {
            if (nums[i] > nums[i + 1]) {
                int temp = nums[i];
                nums[i] = nums[i + 1];
                nums[i + 1] = temp;
                swapped = 1;
            }
        }
        printf("第%zu趟：", j + 1);
        for (size_t i = 0; i < n; i++) {
            printf("%d ", nums[i]);
        }
        printf("\n");
        if (!swapped) {
            break;
        }
    }
}

int main(void) {
    int nums[] = {1, 2, 2, 4};
    size_t n = sizeof(nums) / sizeof(nums[0]);

    int sorted = is_sorted(nums, n);
    if (!sorted) {
        printf("无序\n");
    } else {
        printf("有序\n");
    }

    bubble_sort(nums, n);

    for (size_t i = 0; i < n; i++) {
        printf("%d ", nums[i]);
    }

    

    return 0;
}