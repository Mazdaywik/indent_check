#include <stdio.h>
#include <stdlib.h>

struct Elem {
    struct Elem *prev, *next;
    int v;
    int root;
};

struct Elem *createElement(struct Elem *prev, struct Elem *next, int val){
    struct Elem *newElement = malloc(sizeof(struct Elem));
    newElement->prev = prev;
    newElement->next = next;
    newElement->v = val;
    prev->next = newElement;
    next->prev = newElement;
    newElement->root = 0;
    return newElement;
}

void sorted(struct Elem *root){
    struct Elem *nw = root->next;
    while (nw!=root){
        struct Elem *next = nw->next;
        struct Elem *save = nw;
        nw = nw->prev;
        while (save->v < nw->v && nw != root)
            nw = nw->prev;
        save->prev->next = save->next;
        save->next->prev = save->prev;
        save->next = nw->next;
        nw->next = save;
        save->prev = nw;
        save->next->prev = save;
        nw = next;
    }
}


int main(){
    int n;
    scanf("%d", &n);
    int t;
    struct Elem *root = malloc(sizeof(struct Elem));
    root->v = -1;
    root->prev = root;
    root->next = root;
    root->root = 1;
    for(int i = 0; i < n; i++){
        scanf("%d", &t);
        createElement(root->prev, root, t);
    }
    sorted(root);
    struct Elem*nw = root->next;
    while (nw!=root){
        struct Elem *next = nw->next;
        printf("%d ", nw->v);
        free(nw);
        nw = next;
    }
    free(root);
    return 0;
}

