#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Elem {
    struct Elem *prev, *next;
    int v;
};

struct Elem* createList() {
    struct Elem *head = (struct Elem*)malloc(sizeof(struct Elem));
    head->v = INT_MAX;
    head->prev = head->next = head;
    return head;
}

void insertElem(struct Elem* head, int value) {
    struct Elem *newElem = (struct Elem*)malloc(sizeof(struct Elem));
    newElem->v = value;
    newElem->next = head->next;
    newElem->prev = head;
    head->next->prev = newElem;
    head->next = newElem;
}

void insertionSort(struct Elem* head) {
    struct Elem *i = head->next->next;
    while (i != head) {
        struct Elem *temp = i->next;
        int value = i->v;
        struct Elem *loc = i->prev;

        while (loc != head && loc->v > value) {
            loc = loc->prev;
        }

        if (i->prev != loc) {
            i->prev->next = i->next;
            i->next->prev = i->prev;

            i->next = loc->next;
            i->prev = loc;
            loc->next->prev = i;
            loc->next = i;
        }
        i = temp;
    }
}

void printList(struct Elem* head) {
    struct Elem *temp = head->next;
    while (temp != head) {
        printf("%d ", temp->v);
        temp = temp->next;
    }
    printf("\n");
}

void freeList(struct Elem* head) {
    struct Elem *current = head->next;
    while (current != head) {
        struct Elem *temp = current;
        current = current->next;
        free(temp);
    }
    free(head);
}

int main() {
    int n, value;
    scanf("%d", &n);
    struct Elem* head = createList();
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        insertElem(head, value);
    }
    insertionSort(head);
    printList(head);
    freeList(head);
    return 0;
}