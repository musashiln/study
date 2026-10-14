#include "ds.h"
void seq_init(SeqList *list) { list->length = 0; }
int seq_insert(SeqList *list, size_t index, int value) {
    if (!list || index > list->length || list->length == LIST_CAPACITY) return 0;
    for (size_t i = list->length; i > index; --i) list->data[i] = list->data[i - 1];
    list->data[index] = value; ++list->length; return 1;
}
int seq_delete(SeqList *list, size_t index, int *out) {
    if (!list || index >= list->length) return 0;
    if (out) *out = list->data[index];
    for (size_t i = index; i + 1 < list->length; ++i) list->data[i] = list->data[i + 1];
    --list->length; return 1;
}
int seq_find(const SeqList *list, int value) {
    if (!list) return -1;
    for (size_t i = 0; i < list->length; ++i) if (list->data[i] == value) return (int)i;
    return -1;
}
