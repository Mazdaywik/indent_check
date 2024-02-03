/* 1st semester, 1st module, task 18
 * Searchlist
 * Search through one-way-linked list
 * */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <stdint.h>
#include <string.h>

#ifndef ELEM_H_INCLUDED
#define ELEM_H_INCLUDED

struct Elem {
    enum {
        INTEGER,
        FLOAT,
        LIST
    } tag;
    union {
        int i;
        float f;
        struct Elem *list;
    } value;
    struct Elem *tail;
};

#endif

struct Elem *searchlist(struct Elem *list, int k){
    while (list && !(list->tag == INTEGER && list->value.i == k)){
        list = list->tail;
    }
    return list;
}
