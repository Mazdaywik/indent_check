#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF INT_MAX

struct Elem {
    struct Elem *prev, *next;
    long long int v;
};

typedef struct Elem list_t;


list_t* Initlist() {
    list_t* new = malloc(sizeof(list_t));
    (*new).next = new;
    (*new).prev = new;
    (*new).v = INF;
    return new;
}

void list_insert_before_head(list_t* list, long long int v) {
    list_t* new = malloc(sizeof(list_t));
    (*new).next = (*list).next;
    (*new).prev = list;
    (*new).v = v;
    (*((*list).next)).prev = new;
    (*list).next = new;
}

void list_sort(list_t* list) {
    list_t* i = (*((*list).next)).next;
    while (i != list) 
    {
        list_t* temp = (*i).next;
        long long int elem = (*i).v;
        list_t* loc = (*i).prev;
        while (loc != list && (*loc).v > elem) {
            loc = (*loc).prev;
        }
    (*((*i).prev)).next = (*i).next;
    (*((*i).next)).prev = (*i).prev;
    (*i).prev = loc;
    (*i).next = (*loc).next;
    (*((*loc).next)).prev = i;
    (*loc).next = i;
    i = temp;
    }
}

int main() {
    long long int n;
    scanf("%lld", &n);
    list_t* list = Initlist();
    for (long long int i = 0; i < n; ++i) {
        long long int v;
        scanf("%lld", &v);
        list_insert_before_head(list, v);
    }
    list_sort(list);
    list_t* len = list;
    list = (*list).next;
    while (list != len) {
        printf("%lld ", (*list).v);
        list = (*list).next;
    }
    list = (*list).next;
    while (list != len) {
        list_t* temp = list;
        list = (*list).next;
        free(temp);
    }
    free(len);
    return 0;
}