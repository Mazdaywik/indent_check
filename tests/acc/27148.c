#include <stdio.h>
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <wchar.h>

#define min(a,b) ((a) < (b) ? (a) : (b))
//#define max(a, b) ((a) < (b) ? (b) : (a))
#define maxsz (int)1e6 + 1000
#define inf (int)1e9

typedef long long ll;

int maxx(int x, int y) {
    return x < y ? y : x;
}

struct Elem {
    struct Elem *prev, *next;
    int v;
};

struct DoubleLinkedList {
    struct Elem *prev, *next;
    int v;
};

void InsertBefore(struct Elem *a, struct Elem *b){
    struct Elem *temp;
    temp = b->prev;
    temp->next = a;
    a->prev = temp;
    a->next = b;
    b->prev = a;
}

void Insert(struct DoubleLinkedList *list, int x){
    struct Elem *elem = (struct Elem*) malloc(sizeof(struct Elem));
    elem->v = x;
    struct Elem *cur = list->next;
    while (!((cur->v >= x) || (cur == (struct Elem*)list))){
        cur = cur->next;
    }
    InsertBefore(elem, cur);
}

void Init(struct DoubleLinkedList *list){
    list->v = -inf;
    list->prev = (struct Elem*)list;
    list->next = (struct Elem*)list;
}

int Delete(struct Elem *elem) {
    struct Elem *a = elem->prev;
    struct Elem *b = elem->next;
    a->next = b;
    b->prev = a;
    int value = elem->v;
    free(elem);
    return value;
}

int main(){
    int n;
    struct DoubleLinkedList list;
    Init(&list);
    scanf("%d,", &n);
    for (int i = 0; i < n; ++i){
        int elem;
        scanf("%d", &elem);
        Insert(&list, elem);
    }
    for (int j = 0; j < n; ++j) {
        printf("%d ", Delete(list.next));
    }
    return 0;
}