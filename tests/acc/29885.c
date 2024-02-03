#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct SLList {
    int k, v;
    struct SLList *next;
};


int h(int i, int m) {
    return i % m;
}

struct SLList* InitSLList(int k, int v) {
    struct SLList* el = malloc(sizeof(struct SLList));
    el->k = k;
    el->v = v;
    el->next = NULL;
}

void InsertBeforeHead(struct SLList* l, int k, int v) {
    struct SLList* el = malloc(sizeof(struct SLList));
    el->k = k;
    el->v = v;
    el->next = l->next;
    l->next = el;
}

void Insert(struct SLList **t, int k, int v, int m) {
    int i = h(k, m);
    InsertBeforeHead(t[i], k, v);
}

struct SLList *ListSearch(struct SLList *l, int k) {
    struct SLList *x = l;
    while (x != NULL && x->k != k) {
        x = x->next;
    }
    return x;
}

void Lookup(struct SLList **t, int k, int m) {
    struct SLList *p = ListSearch(t[h(k, m)], k);
    if (p == NULL) printf("%d\n", 0);
    else printf("%d\n", p->v);
}

int main() {
    int m;
    scanf("%d", &m);

    struct SLList **hash_table = calloc(m, sizeof(struct SLList));
    for (int i = 0; i < m; ++i) {hash_table[i] = InitSLList(0, 0);}

    while (1) {
        char op[10];
        scanf("%s", op);
        if (strcmp(op, "ASSIGN") == 0) {
            int i, v;
            scanf("%d %d", &i, &v);
            Insert(hash_table, i, v, m);
        } else if (strcmp(op, "AT") == 0) {
            int i;
            scanf("%d", &i);
            Lookup(hash_table, i, m);
        } else {
            break;
        }
    }
    
    for (int i = 0; i < m; ++i) {
        struct SLList *j = hash_table[i];
        while (hash_table[i] != NULL) {
            j = j->next;
            free(hash_table[i]);
            hash_table[i] = j;
        }
    }
    free(hash_table);
}