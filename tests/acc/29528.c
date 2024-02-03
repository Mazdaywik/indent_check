#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

struct Elem {
    struct Elem *prev, *next;
    int v;
};

struct Elem* InitDoubleLinkedList(){
    struct Elem *l = calloc(1, sizeof(struct Elem));
    l->prev = l;
    l->next = l;
    return l;
}
int ListEmpty(struct Elem *l){
    if (l->next == l){
        return 1;
    }
    return 0;
}
int ListLength(struct Elem *l){
    int len = 0;
    struct Elem *x = l;
    while (x->next != l){
        len += 1;
        x = x->next;
    }
    return len;
}
void InsertAfter(struct Elem *x, struct Elem *y){
    struct Elem *z = x->next;
    x->next = y;
    y->prev = x;
    y->next = z;
    z->prev = y;
}
void delete(struct Elem *x){
    struct Elem *y = x->prev;
    struct Elem *z = x->next;
    y->next = z;
    z->prev = y;
    x->prev = NULL;
    x->next = NULL;
}
int main(){
    int n, num;
    struct Elem *list = InitDoubleLinkedList();
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        struct Elem *new;
        scanf("%d", &num);
        new = InitDoubleLinkedList();
        new->v = num;
        InsertAfter(list, new);
    }
    struct Elem *i;
    struct Elem *j;
    i = list->next;
    while (i != list){
        j = i->prev;
        while (j != list && i->v < j->v){
            j = j->prev;
        }
        delete(i);
        InsertAfter(j, i);
        i = i->next;
    }
    i = list->next;
    struct Elem *k;
    while (i != list){
        printf("%d ", i->v);
        k = i->next;
        free(i);
        i = k;
    }
    free(list);
}
