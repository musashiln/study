#include <stdio.h>
#include <stdlib.h>

int merge_sorted(const int a[], int len_a,
                  const int b[], int len_b, int out[]) {
    if (len_a < 0 || len_b < 0) {
        return 0;
    }
    if (out == NULL) {
        return 0;
    }
    int index_a = 0;
    int index_b = 0;
    int i = 0;
    for (; i < len_a + len_b; i++) {
        if ((index_a < len_a) && (index_b < len_b)) {
            if (a[index_a] <= b[index_b]) {
                out[i] = a[index_a];
                index_a++;
            } else {
                out[i] = b[index_b];
                index_b++;
            }
        } else {
            break;
        }
    }
    for (; i < len_a + len_b; i++) {
        if (index_a == len_a) {
            out[i] = b[index_b];
            index_b++;
        } else if (index_b == len_b) {
            out[i] = a[index_a];
            index_a++;
        }
    }
    return 1;
}

int main(void) {
    int a[] = {3, 5};
    int len_a = (int)(sizeof(a) / sizeof(a[0]));

    int b[] = {2, 4};
    int len_b = (int)(sizeof(b) / sizeof(b[0]));

    int *out = (int *)malloc(sizeof(int) * (len_a + len_b));

    if (out == NULL) {
        printf("内存分配失败\n");
        return 1;
    }

    int is_merged = merge_sorted(a, 0, b, len_b, NULL);

    if (is_merged) {
        for (int i = 0; i < 0 + len_b; i++) {
            printf("%d ", out[i]);
        }
    }

    free(out);

    return 0;
}