/* Wangdao 2.2.2: fixed-capacity sequential list, runnable C11 example.
 * Positions start at 1. Array subscripts start at 0.
 * Build: gcc -std=c11 -Wall -Wextra -Wpedantic wangdao_2_2_2.c -o seqlist.exe
 */
#include <stdbool.h>
#include <stdio.h>

#define MaxSize 50
typedef int ElemType;

typedef struct {
    ElemType data[MaxSize];
    int length;
} SqList;

/* Preconditions: initialized list; 0 <= length <= MaxSize.
 * Output e must point to a separate ElemType object, outside the list.
 */
bool ListInsert(SqList *L, int i, ElemType e) {
    if (L == NULL || i < 1 || i > L->length + 1)
        return false;
    if (L->length >= MaxSize)
        return false;

    /* Move backwards to avoid overwriting elements not yet moved. */
    for (int j = L->length; j >= i; --j)
        L->data[j] = L->data[j - 1];

    L->data[i - 1] = e;
    ++L->length;
    return true;
}

bool ListDelete(SqList *L, int i, ElemType *e) {
    if (L == NULL || e == NULL || i < 1 || i > L->length)
        return false;

    *e = L->data[i - 1];
    /* Move forwards to fill the gap. */
    for (int j = i; j < L->length; ++j)
        L->data[j - 1] = L->data[j];

    --L->length;
    return true;
}

int LocateElem(const SqList *L, ElemType e) {
    if (L == NULL)
        return 0;

    for (int i = 0; i < L->length; ++i) {
        if (L->data[i] == e)
            return i + 1;
    }
    return 0;
}

void PrintList(const SqList *L) {
    printf("[");
    for (int i = 0; i < L->length; ++i)
        printf("%s%d", i == 0 ? "" : ", ", L->data[i]);
    printf("] (length=%d)\n", L->length);
}

int main(void) {
    const SqList original = {{25, 34, 57, 16, 48, 9, 63}, 7};
    SqList insertion = original;
    SqList deletion = original;
    ElemType removed = 0;

    printf("Original: ");
    PrintList(&original);

    if (!ListInsert(&insertion, 4, 50)) {
        fprintf(stderr, "Insertion failed\n");
        return 1;
    }
    printf("Insert 50 at position 4: ");
    PrintList(&insertion);

    /* Figure 2.2(b) starts from the original list, independently. */
    if (!ListDelete(&deletion, 4, &removed)) {
        fprintf(stderr, "Deletion failed\n");
        return 1;
    }
    printf("Delete position 4: ");
    PrintList(&deletion);
    printf("Removed value: %d\n", removed);
    printf("Find 48 in original: position %d\n", LocateElem(&original, 48));
    printf("Find 99 in original: position %d\n", LocateElem(&original, 99));
    return 0;
}
