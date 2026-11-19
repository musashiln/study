#include <stdio.h>
#include <stdlib.h>

int push_back(int **nums, int *n, int *capacity, int value) {
    if ((*n) == (*capacity)) {
        int *temp = (int *)realloc(*nums, 2 * (*capacity) * sizeof(**nums));
        if (temp == NULL) {
            printf("扩容失败\n");
            return 0;
        }
        *nums = temp;
        *capacity = 2 * (*capacity);
    }
    (*nums)[*n] = value;
    (*n)++;
    return 1;
}

int main(void) {
    int capacity = 2;
    int n = 0;
    int *nums = (int *)malloc(capacity * sizeof(int));
    if (nums == NULL) {
        printf("内存分配失败\n");
        return 1;
    }

    int values[] = {3, 5, 8, 13, 21};
    int count = (int)(sizeof(values) / sizeof(values[0]));

    for (int i = 0; i < count; i++) {
        int is_push_back = push_back(&nums, &n, &capacity, values[i]);
        if (!is_push_back) {
            free(nums);
            return 1;
        }
        printf("(n, capacity) = (%d, %d)\n", n, capacity);
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", nums[i]);
    }
    free(nums);
    return 0;
}