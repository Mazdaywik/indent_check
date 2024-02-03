#include <stdio.h>
#include <stdlib.h>

struct Elem {
    struct Elem *prev, *next;
    int v;
};

int main(int argc, char** argv) {
    int n, num;
    scanf("%d", &n);
    struct Elem *start = malloc(sizeof(struct Elem));
    start->next = start;
    start->prev = start;
    struct Elem *now = start;
    for(int i = 0 ; i < n ; i++){
        scanf("%d", &num);
        struct Elem *new = malloc(sizeof(struct Elem));
        new->prev = now;
        new->next = now->next;
        now->next->prev = now;
        now->next = new;
        now = new;
        now->v = num;
    }
    struct Elem *nowNext;
    for(now = start->next ; now != start; now = nowNext){
        nowNext = now->next;
        struct Elem *pred = now->prev;
        while (pred!=start && now->v < pred->v)
            pred = pred->prev;
        struct Elem *next = pred->next;
        if(now == pred->next){
            next = pred->next->next;
        }
        now->next->prev = now->prev;
        now->prev->next = now->next;
        now->next = next;
        now->prev = pred;
        next->prev = now;
        pred->next = now;
    }
    for(now = start->next ; now != start; now = nowNext){
        nowNext = now->next;
        printf("%d ", now->v);
        free(now);
    }
    free(start);
    return 0;
}

