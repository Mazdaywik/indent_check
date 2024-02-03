#include <stdio.h>
#include <stdlib.h>
struct elem {
    struct elem *prev, *next;
    int v;
};
struct elem *initdlilist()
{
    struct elem *l = (struct elem*)calloc(1, sizeof(struct elem));
    l->prev = l;
    l->next = l;
    return l;
}
int listempty(struct elem *l)
{
    if(l->next == l) return 1;
    return 0;
}
int listlength(struct elem *l)
{
    int len = 0;
    struct elem *x = l;
    while (x->next != l){
        len++;
        x = x->next;
    }
}
struct elem *listsearch(struct elem *l, int v)
{
    struct elem *x = l->next;
    while(x!=l && x->v != v) x = x->next;
    return x;
}

void insertafter(struct elem *x, struct elem *y)
{
    struct elem *z = x->next;
    x->next = y;
    y->prev = x;
    y->next = z;
    z->prev = y;
}

void delete(struct elem *x)
{
    struct elem *y = x->prev;
    struct elem *z = x->next;
    y->next = z;
    z->prev = y;
    x->prev = NULL;
    x->next = NULL;
}

void isort(struct elem *l)
{
    struct elem  *i = l->next->next;
    while (i != l){
        struct elem *loc = i->prev;
        while (loc != l && loc->v > i->v){
            loc= loc->prev;
        }
        delete(i);
        insertafter(loc, i);
        i = i->next;
    }
}

int main(int argc, char** argv)
{
    struct elem *dlist = initdlilist();
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        struct elem *x = (struct elem*)calloc(1, sizeof(struct elem));
        scanf("%d", &(x->v));
        insertafter(dlist, x);
    }
    isort(dlist);
    struct elem *p = dlist->next;
    while(p != dlist){
        printf("%d ", p->v);
        p = p->next;
        free(p->prev);
    }
    free(dlist);
    return 0;
}