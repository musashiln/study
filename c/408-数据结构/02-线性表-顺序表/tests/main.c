#include <assert.h>
#include <stdio.h>
#include "ds.h"
int main(void) {
    SeqList list; int removed = 0; seq_init(&list);
    assert(seq_insert(&list, 0, 10)); assert(seq_insert(&list, 1, 20));
    assert(seq_insert(&list, 1, 15)); assert(seq_find(&list, 15) == 1);
    assert(seq_delete(&list, 1, &removed) && removed == 15);
    assert(list.length == 2); puts("sequence list tests passed"); return 0;
}
