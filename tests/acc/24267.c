#include "elem.h"
#include <stddef.h>

struct Elem *searchlist(struct Elem *list, int k) {
    if (list == NULL) {
        return NULL;
    }
    if (list->tag == INTEGER && list->value.i == k) {
        return list;
    }
    return searchlist(list->tail, k);
}