#include <stdio.h>

void shell_sort(int arr[], int n) {
    // gap 逐步减半，直到 1
    for (int gap = n / 2; gap > 0; gap /= 2) {
        // 对每个元素，按 gap 间隔进行插入排序
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j = i;

            // 把比 temp 大的元素向后移动 gap 个位置
            while (j >= gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap];
                j -= gap;
            }

            arr[j] = temp;
        }
    }
}

void print_array(const int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(void) {
    int arr[] = {9, 8, 3, 7, 5, 6, 4, 1, 2};
    int n = (int)(sizeof(arr) / sizeof(arr[0]));

    printf("排序前：");
    print_array(arr, n);

    shell_sort(arr, n);

    printf("排序后：");
    print_array(arr, n);

    return 0;
}