#include <stdio.h>

// 找到时返回下标，找不到时返回 -1
int binary_search(const int arr[], int n, int target)
{
    int left = 0;
    int right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}

int main(void)
{
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 45, 56};
    int n = (int)(sizeof(arr) / sizeof(arr[0]));
    int target = 23;

    int index = binary_search(arr, n, target);

    if (index == -1) {
        printf("未找到 %d\n", target);
    } else {
        printf("找到 %d，下标为 %d\n", target, index);
    }

    return 0;
}