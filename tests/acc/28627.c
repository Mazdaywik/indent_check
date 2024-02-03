#include <stdlib.h>
#include "elem.h"

struct Elem  *searchlist(struct Elem  *list, int k)
{
    return (list == NULL || (list->tag == INTEGER && list->value.i == k) ) ? list : searchlist(list->tail, k);
}
