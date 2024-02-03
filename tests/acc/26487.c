#include <stdio.h>
#include <stdlib.h>

struct Elem {
    struct Elem *prev, *next;
    int v;
};

void insertSorted(struct Elem* head, int value) {
    struct Elem* current = head->next;
    while (current != head && current->v < value) {
        current = current->next;
    }
    struct Elem* newElem = (struct Elem*)malloc(sizeof(struct Elem));
    newElem->v = value;
    newElem->prev = current->prev;
    newElem->next = current;
    current->prev->next = newElem;
    current->prev = newElem;
}

void printList(struct Elem* head) {
    struct Elem* current = head->next;
    while (current != head) {
        printf("%d ", current->v);
        current = current->next;
    }
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);

    struct Elem* head = (struct Elem*)malloc(sizeof(struct Elem));
    head->prev = head;
    head->next = head;

    for (int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);
        insertSorted(head, value);
    }

    printList(head);

    struct Elem* current = head->next;
    while (current != head) {
        struct Elem* temp = current;
        current = current->next;
        free(temp);
    }
    free(head);

    return 0;
}