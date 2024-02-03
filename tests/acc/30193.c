#include <stdio.h>
#include <stdlib.h>

typedef struct Elem {
    struct Elem *prev, *next;
    int v;
}list;

list *InitDoubleLinkedList() {
    list *l = malloc(sizeof(list));
    l->next = l;
    l->prev = l;
    return l;
}

void InsertAfter(list* x, list* y) {
    list *z = x->next;
    x->next = y;
    y->prev = x;
    y->next = z;
    z->prev = y;
}

void InsertSort(list* l) {
    list *i = (*l).next->next, *j;
    while(i != l) {
        for (j = (*i).prev; j != l && (*i).v < (*j).v; j = (*j).prev);
        list *Prev = (*i).prev;
        list *Next = (*i).next;
        (*Prev).next = Next;
        (*Next).prev = Prev;
        InsertAfter(j, i);
        i = (*i).next;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    list *l = InitDoubleLinkedList();
    for (int i = 0; i < n; i++) {
        list* elem = malloc(sizeof(list));
        scanf("%d", &(elem->v));
        InsertAfter(l, elem);
    }
    InsertSort(l);
    list *p = l->next;
    while (p != l) {
        printf("%d ", p->v);
        p = p->next;
    }
    p = l->next;
    while (p != l) {
        list *temp = p;
        p = p->next;
        free(temp);
    }
    free(l);
    return 0;
}