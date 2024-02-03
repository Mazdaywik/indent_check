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
    l->k = 0;
    l->v = 0;
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

void DeleteHead(struct Elem *l)
{
    struct Elem *y = l;
    l = y->next;
    
    y->next = NULL;
    free(y);
}

void DeleteAfter(struct Elem *x)
{
    struct Elem *y = x->next;
    x->next = y->next;
    
    y->next = NULL;
    free(y);
}

void SearchAndDelete(struct Elem *l, int k)
{
    struct Elem *y = NULL;
    struct Elem *x = l;
    while (x != NULL) {
        if (x->k == k) {
            if (y == NULL) DeleteHead(l);
            else DeleteAfter(y);
            break;
        }
        y = x;
        x = x->next;
    }
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

void InsertBeforeHead(struct Elem *l, int k, int v)
{
    struct Elem* temp = malloc(sizeof(struct Elem));
    temp->k = k;
    temp->v = v;
    temp->next = l->next;
    l->next = temp;
}

void Insert(struct Elem **t, int k, int v, int m)
{
    int i = hash(k, m);
    SearchAndDelete(t[i], k);
    if (v != 0) InsertBeforeHead(t[i], k, v);
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

