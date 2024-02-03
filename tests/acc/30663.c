//большая часть кода с презентации

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Elem {
    struct Elem *next;
    int ind;
    int num;
};

int h(int k, int m){
    return k % m;
}

void *InitHashTable(int m, struct Elem ***t){
    return (*t) = calloc(m, sizeof(struct Elem*));
}

int ListEmpty(struct Elem *t){
    return t == NULL;
}

int MapEmpty(struct Elem **t, int m){
    int i = 0;
    while (i < m){
        if (!ListEmpty(t[i])) return 0;
        i = i + 1;
    }
    return 1;
}

struct Elem *ListSearch(struct Elem *l, int v){
    struct Elem *x = l;
    while (x!=NULL && x->ind != v)
        x = x->next;
    return x;
}

struct Elem *ListSearchPrev(struct Elem *l, int v){
    struct Elem *x = l;
    while (x!=NULL && x->next!=NULL && x->next->ind != v)
        x = x->next;
    if(x!=NULL && x->next == NULL)
        return NULL;
    return x;
}

int MapSearch(struct Elem **t, int k, int m){
    struct Elem *search = ListSearch(t[h(k, m)], k);
    if(search == NULL)
        return 0;
    return search->num;
}

void InsertBeforeHead(struct Elem **l, int y, int ind){
    struct Elem *new = malloc(sizeof(struct Elem));
    new->next = *l;
    new->ind = ind;
    new->num = y;
    (*l) = new;
}

void Insert(struct Elem **t, int k, int v, int m){
   int i = h(k, m);
   if (ListSearch(t[i], k) != NULL){
       struct Elem *search = ListSearch(t[i], k);
       if(v != 0){
           search->num = v;
       } else{
           struct Elem *prev = ListSearchPrev(t[i], k);
           if(prev == NULL){
               struct Elem *save = t[i];
               t[i] = t[i]->next;
               free(save);
           }else{
               struct Elem *save = prev->next->next;
               free(prev->next);
               prev->next=save;
           }
       }
   }else
       InsertBeforeHead(&(t[i]), v, k);
}

void ListClean(struct Elem *l){
    while (l!=NULL){
        struct Elem *save = l->next;
        free(l);
        l = save;
    }
}

void cleanup(struct Elem **t, int m){
    int i = 0;
    while (i < m){
        ListClean(t[i]);
        i = i + 1;
    }
    free(t);
}

int main() {
    struct Elem **array;
    int m;
    scanf("%d", &m);
    InitHashTable(m, &array);
    while (1) {
        char action[19];
        scanf("%s", action);
        if (strcmp(action, "ASSIGN") == 0) {
            int ind, v;
            scanf("%d%d", &ind, &v);
            Insert(array, ind, v, m);
        }
        else if (strcmp(action, "AT") == 0) {
            int ind;
            scanf("%d", &ind);
            printf("%d\n", MapSearch(array, ind, m));
        }
        else if (strcmp(action, "END") == 0) {
            break;
        }
    }
    cleanup(array, m);
    return 0;
}