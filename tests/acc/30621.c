#include <math.h>
#include <stdio.h>
#include "elem.h"

struct Elem *searchlist(struct Elem *list, int k) {

    while (list != NULL) {
        if (list == list->tail) {
            break;
        }
        if (list->tag == INTEGER && list->value.i == k) {
            return list;
        }
        list = list->tail;
    }

    return NULL;
}