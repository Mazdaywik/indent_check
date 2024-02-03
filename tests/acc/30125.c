#include <stdio.h>
#include <stdlib.h>

struct Elem {
    struct Elem *prev, *next;
    int v;
};

void insertSort(struct Elem *head, int n) {
    for (int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);
        struct Elem *newElem = (struct Elem *)malloc(sizeof(struct Elem));
        newElem->v = value;
        struct Elem *helpElem = head->next;
        while (helpElem != head && helpElem->v < value) 
            helpElem = helpElem->next;
        newElem->prev = helpElem->prev;
        newElem->next = helpElem;
        helpElem->prev->next = newElem;
        helpElem->prev = newElem;
    }
}

void printArr(struct Elem *head) {
    for (struct Elem *i = head->next; i != head; i = i->next)
        printf("%d ", i->v);
    printf("\n");
}

void freeList(struct Elem *head) {
    struct Elem *helpElem = head->next;
    while (helpElem != head) {
        struct Elem *temp = helpElem->next;
        free(helpElem);
        helpElem = temp;
    }
    free(head);
}

int main() {
    int n;
    scanf("%d", &n);
    
    struct Elem *head = (struct Elem *)malloc(sizeof(struct Elem));
    head->prev = head;
    head->next = head;
    
    insertSort(head, n);
    printArr(head);
    freeList(head);
    return 0;
}