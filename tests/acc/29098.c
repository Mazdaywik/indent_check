#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Elem {
    struct Elem *prev, *next;
    int v;
};

void add(struct Elem *root, int v){
    struct Elem *new = malloc(sizeof(struct Elem));
    new->next = root;
    new->prev = root->prev;
    new->v = v;
    root->prev->next = new;
    root->prev = new;
}

struct Elem *down(struct Elem *root, struct Elem *nextElem, int value){
    struct Elem *now = nextElem->prev;
    if(root != now && now->v > value)
        return down(root, now, value);
    return now;
}

void insertionSort(struct Elem *root){
    struct Elem *endSorted = root->next;
    while (endSorted != root){
        struct Elem *nextElem = endSorted;
        struct Elem *stop = down(root, nextElem, nextElem->v);
        endSorted = nextElem->next;
        nextElem->prev->next = nextElem->next;
        nextElem->next->prev = nextElem->prev;
        stop->next->prev = nextElem;
        nextElem->next = stop->next;
        stop->next = nextElem;
        nextElem->prev = stop;
    }
}

void free_list(struct Elem *root, struct Elem *now){
    if(now!=root){
        free_list(root, now->next);
        free(now);
    }
}

int main(int argc, char *argv[]) {
    int n;
    scanf("%d", &n);
    struct Elem root;
    root.next = &root;
    root.prev = &root;
    root.v = 0;
    for(int i = 0 ; i < n; i++){
        int value;
        scanf("%d", &value);
        add(&root, value);
    }
    insertionSort(&root);
    struct Elem *nextElem = root.next;
    while (nextElem != &root){
        printf("%d ", nextElem->v);
        nextElem = nextElem->next;
    }
    free_list(&root, root.next);
    return 0;
}