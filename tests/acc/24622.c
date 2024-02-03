#include <string.h>
#include <stdlib.h>
#include <stdio.h>

struct Elem {
    struct Elem *prev, *next;
    int v;
};

void print(struct Elem* tail) {
    if (tail->prev != NULL) {
        print(tail->prev);
    }
    printf("%d ", tail->v);
}

void clear(struct Elem* tail) {
    if (tail->prev != NULL) {
        clear(tail->prev);
    }
    free(tail);
}

void sort(struct Elem* tail) {
    while (tail != NULL) {
        int x = tail->v;
        struct Elem *i = tail->next;
        struct Elem *last = tail;
        while (i != NULL && i->v <= x) {
            int tmp = i->v;
            last = i;
            i->v = i->prev->v;
            i->prev->v = tmp;
            i = i->next;
        }
        last->v = x;
        tail = tail->prev;
    }
}

int main() {
    struct Elem* tail = NULL;
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        if (i == 0) {
            tail = malloc(sizeof(struct Elem));
            tail->prev = NULL;
            tail->next = NULL;
            tail->v = x;
        } else {
            struct Elem* new_tail = malloc(sizeof(struct Elem));
            new_tail->v = x;
            new_tail->next = NULL;
            new_tail->prev = tail;
            tail->next = new_tail;
            tail = new_tail;
        }
    }
    sort(tail);
    print(tail);
    clear(tail);
    return 0;
}