#include <stddef.h>
#include "elem.h"

struct Elem* searchlist(struct Elem* list, int k) {
    if (list == NULL) {
        return NULL;
    }

    struct Elem* current = list;
    while (current != NULL) {
        if (current->tag == INTEGER && current->value.i == k) {
            return current; 
        }
        current = current->tail; 
    }

    return NULL; 
}
