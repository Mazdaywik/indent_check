#include <stdio.h>
#include <stdlib.h>

struct Elem {
    struct Elem *prev, *next;
    int v;
};

struct Elem* CreateElem(int value) {
    struct Elem* newElem = (struct Elem*) malloc(sizeof(struct Elem));
    newElem->prev = NULL;
    newElem->next = NULL;
    newElem->v = value;
    return newElem;
}

void InsertAfter(struct Elem** head, struct Elem* newElem) {
    if (*head == NULL) {
        *head = newElem;
    } else {
        newElem->next = *head;
        (*head)->prev = newElem;
        *head = newElem;
    }
}

void PrintList(struct Elem* head) {
    struct Elem* currentElem = head;
    while (currentElem != NULL) {
        printf("%d ", currentElem->v);
        currentElem = currentElem->next;
    }
    printf("\n");
}

void InsertionSort(struct Elem** head) {
    struct Elem* current = *head;
    while (current != NULL) {
        struct Elem* element = current;
        while (element->prev != NULL && element->prev->v > element->v) {
            int swap = element->prev->v;
            element->prev->v = element->v;
            element->v = swap;
            element = element->prev;
        }
        current = current->next;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    struct Elem* list = NULL;
    int i = 0;
    while (i < n) {
        int num;
        scanf("%d", &num);
        struct Elem* newElem = CreateElem(num);
        InsertAfter(&list, newElem);
        i++;
    }
    InsertionSort(&list);
    PrintList(list);
    while (list != NULL) {
        struct Elem* nextElem = list->next;
        free(list);
        list = nextElem;
    }
    return 0;
}
