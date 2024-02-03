#include "elem.h"
#include <stddef.h>

struct Elem *searchlist(struct Elem *list, int k) {
    while (list != NULL) {
        if (list->tag == INTEGER && list->value.i == k) {
            return list;
        }
        list = list->tail;
    }
    return NULL;
}
