#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Elem {
    int k;
    int v;
    struct Elem *next;
};

struct Elem* InitSingleLinkedList()
{
    struct Elem *l = (struct Elem*) malloc(sizeof(struct Elem));
    l->next = NULL;
    return l;
}

int ListEmpty(struct Elem *l)
{
    return (l == NULL);
}

struct Elem* ListSearch(struct Elem *l, int v)
{
    struct Elem *x;
    x = l;
    while (x != NULL && x->k != v) {
        x = x->next;
    }
    return x;
}

struct Elem* InsertBeforeHead(struct Elem *l, struct Elem *y)
{
    y->next = l;
    l = y;
    return y;
}

int hash(int k, int m)
{
    return k % m;
}

int Lookup(struct Elem **t, int k, int m)
{
    struct Elem *p = ListSearch(t[hash(k, m)], k);
    int v;
    if (p == NULL) v = 0;
    else v = p->v;
    return v;
}

void Insert(struct Elem **t, int k, int v, int m)
{
    int i = hash(k, m);
    struct Elem *p = InitSingleLinkedList();
    p->k = k;
    p->v = v;
    t[i] = InsertBeforeHead(t[i], p);
}

void Table(struct Elem **t, int m)
{
    for (int i = 0; i < m; i++) {
        t[i] = InitSingleLinkedList();
        t[i]->k = 0;
        t[i]->v = 0;
    }
    
}

int main()
{
    int m;
    scanf("%d", &m);
    
    struct Elem **t;
    t = (struct Elem**) calloc(m, sizeof(struct Elem*));
    Table(t, m);
    
    char action[10];
    scanf("%s", action);
    
    while (strcmp("END", action) != 0) {
        if (strcmp("AT", action) == 0) {
            int i;
            scanf("%d", &i);
            printf("%d\n", Lookup(t, i, m));
        } else if (strcmp("ASSIGN", action) == 0) {
            int i, v;
            scanf("%d %d", &i, &v);
            Insert(t, i, v, m);
        }
        scanf("%s", action);
    }
    
    for (int i = 0; i < m; i++) {
        struct Elem *el;
        el = t[i];
        while (el) {
            struct Elem *temp;
            temp = el->next;
            free(el);
            el = temp;
        }
    }
    free(t);
    return 0;
}

