#ifndef SEQ_LIST_H
#define SEQ_LIST_H
#include <stddef.h>
#define LIST_CAPACITY 100
typedef struct { int data[LIST_CAPACITY]; size_t length; } SeqList;
void seq_init(SeqList *list);
int seq_insert(SeqList *list, size_t index, int value);
int seq_delete(SeqList *list, size_t index, int *out);
int seq_find(const SeqList *list, int value);
#endif
