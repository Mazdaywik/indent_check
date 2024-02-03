#include <stdio.h>
#include <stdlib.h>

typedef struct Elem {
    struct Elem *prev, *next;
    int v;
} Elem;

void addToList(Elem** list, Elem** last, int value) {
    Elem* newNode = (Elem*)malloc(sizeof(Elem));
    newNode->v = value;

    if (*list == NULL) {
        newNode->next = newNode->prev = newNode;
        *list = newNode;
    } else {
        newNode->prev = *last;
        newNode->next = (*last)->next;
        (*last)->next->prev = newNode;
        (*last)->next = newNode;
    }
    *last = newNode;
}

void listInsertionSort(Elem** list) {
    if (*list == NULL || (*list)->next == *list) return;

    Elem *current = (*list)->next;
    while (current != *list) {
        Elem *next = current->next;
        if (current->v < current->prev->v) {
            Elem *search = current->prev;
            while (search != *list && current->v < search->v) {
                search = search->prev;
            }

            current->prev->next = current->next;
            current->next->prev = current->prev;

            current->next = search->next;
            search->next->prev = current;
            current->prev = search;
            search->next = current;

            if (current->prev == *list && current->v < (*list)->v) {
                *list = current;
            }
        }

        current = next;
    }
}




void printList(const Elem* list, int n) {
    const Elem *temp = list;
    for (int i = 0; i < n; i++) {
        printf("%d ", temp->v);
        temp = temp->next;
    }
    printf("\n");
}

void freeList(Elem** list) {
    if (*list == NULL) return;

    Elem *current = *list;
    Elem *next;

    do {
        next = current->next;
        free(current);
        current = next;
    } while (current != *list);

    *list = NULL;
}


int main() {
    Elem *list = NULL;
    Elem *last = NULL;
    int n, value;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        addToList(&list, &last, value);
    }

    listInsertionSort(&list);
    printList(list, n);

    freeList(&list);

    return 0;
}