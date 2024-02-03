#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>

struct Elem {
    struct Elem *prev, *next;
    int v;
};

void InitDoubleLinkedList(struct Elem *list){
    list->next = list;
    list->prev = list;
    list->v = INT_MIN;
}

void InsertBeforeHead(int v, struct Elem *list, struct Elem *e){
    e->prev = list;
    e->next = list->next;
    e->v = v;
    list->next->prev = e;
    list->next = e;
}

void InsertSearch(struct Elem *list){
    struct Elem *i = list->next->next;
    while(i->v > INT_MIN){
        struct Elem *e = i->prev;
        while(e->v > i->v){
            e = e->prev;
        }
        i->next->prev = i->prev;
        i->prev->next = i->next;
        i->next = e->next;
        i->prev = e;
        e->next->prev = i;
        e->next = i;
        i = i->next;
    }
}


int main(int args, char **argv){
    int n = 0;
    scanf("%d", &n);
    struct Elem *list = calloc(n, sizeof(struct Elem));
    InitDoubleLinkedList(list);
    for(int i = 0; i < n; i++){
        struct Elem *e = calloc(1, sizeof(struct Elem));
        int v = 0;
        scanf("%d", &v);
        InsertBeforeHead(v, list, e);
    }
    InsertSearch(list);
    for(int i = 0; i < n; i++){
        int v = list->next->v;
        printf("%d ", v);
        struct Elem *_l = list;
        list = list->next;
        free(_l);
    }
    free(list);
    return 0;
}
