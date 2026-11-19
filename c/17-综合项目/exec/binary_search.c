#include <stdio.h>

int binary_search(const int nums[], int n, int target, int *index)
{
    int left = 0;
    int right = n;

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (target == nums[mid]) {
            *index = mid;
            return 1;
        } else if (target < nums[mid]) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    return 0;
}

int main(void) {
    int nums[] = {1, 3, 5, 7, 9, 11, 13};
    int n = (int)(sizeof(nums) / sizeof(nums[0]));
    int index = -1;
    
    int is_search = binary_search(nums, n, 8, &index);

    if(is_search) {
        printf("%d\n", index);
    } else {
        printf("没找到\n");
    }

    return 0;
}