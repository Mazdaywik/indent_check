#include <stdio.h>
#include <stdlib.h>

struct Elem {
    struct Elem *prev, *next;
    int v;
};

struct Elem* InitDoubleLinkedList()
{
    struct Elem *l = malloc(sizeof(struct Elem));
    l->prev = l;
    l->next = l;
    l->v = 2000000000;
    return l;
}

void InsertAfter(struct Elem *x, struct Elem *y)
{
    struct Elem *z;
    z = x->next;
    x->next = y;
    y->prev = x;
    y->next = z;
    z->prev = y;
}

void Delete(struct Elem *x)
{
    struct Elem *y;
    y = x->prev;
    struct Elem *z;
    z = x->next;
    y->next = z;
    z->prev = y;
    
    x->prev = NULL;
    x->next = NULL;
}

void InsertSort(struct Elem *l)
{
    struct Elem *i;
    i = l->next;
    while (i != l) {
        struct Elem *loc;
        loc = i->prev;
        int el;
        el = i->v;
        while (loc != l && loc->v > el)
            loc = loc->prev;
        Delete(i);
        InsertAfter(loc, i);
        i = i->next;
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    
    struct Elem *l = InitDoubleLinkedList();
    struct Elem *el;
    
    for (int i = 0; i < n; i++) {
        el = (struct Elem*) malloc(sizeof(struct Elem));
        scanf("%d", &(el->v));
        InsertAfter(l, el);
    }
    
    InsertSort(l);
    
    for (el = l->next; el != l; el = el->next)
        printf("%d ", el->v);
    
    el = l->next;
    while (el != l) {
        el = el->next;
        free(el->prev);
    }

    free(l);
    return 0;
}
