#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int n;
    int capacity;
} IntArray;

int push_back(IntArray *arr, int value) {

    if ((arr->n) == (arr->capacity)) {
        int *temp = (int *)realloc(arr->data, 2 * (arr->capacity) * sizeof(*(arr->data)));
        if (temp == NULL) {
            printf("扩容失败\n");
            return 0;
        }
        arr->data = temp;
        arr->capacity = 2 * (arr->capacity);
    }
    (arr->data)[arr->n] = value;
    (arr->n)++;
    return 1;
}

int main(void) {
    IntArray arr = {NULL, 0, 2};
    arr.data = (int *)malloc((arr.capacity) * sizeof(int));
    if (arr.data == NULL) {
        printf("内存分配失败\n");
        return 1;
    }

    int values[] = {3, 5, 8, 13, 21};
    int count = (int)(sizeof(values) / sizeof(values[0]));

    for (int i = 0; i < count; i++) {
        int is_push_back = push_back(&arr, values[i]);
        if (!is_push_back) {
            free(arr.data);
            return 1;
        }
        printf("(n, capacity) = (%d, %d)\n", arr.n, arr.capacity);
    }

    for (int i = 0; i < arr.n; i++) {
        printf("%d ", arr.data[i]);
    }
    free(arr.data);
    return 0;
}