#include <stdio.h>
#include <stdlib.h>

struct Elem {
    struct Elem* prev, * next;
    int v;
};

struct Elem* createElem(int value) {
    struct Elem* newElem = (struct Elem*)malloc(sizeof(struct Elem));
    if (newElem == NULL) {
        fprintf(stderr, "Ошибка выделения памяти\n");
        exit(EXIT_FAILURE);
    }
    newElem->prev = NULL;
    newElem->next = NULL;
    newElem->v = value;
    return newElem;
}

void insertSorted(struct Elem** head, struct Elem* newElem) {
    if (*head == NULL) {
        *head = newElem;
        (*head)->prev = *head;
        (*head)->next = *head;
        return;
    }

    struct Elem* current = *head;

    do {
        if (current->v >= newElem->v) {
            newElem->next = current;
            newElem->prev = current->prev;
            current->prev->next = newElem;
            current->prev = newElem;
            if (current == *head) {
                *head = newElem;
            }
            return;
        }
        current = current->next;
    } while (current != *head);

    newElem->next = *head;
    newElem->prev = (*head)->prev;
    (*head)->prev->next = newElem;
    (*head)->prev = newElem;
}

void freeList(struct Elem* head) {
    if (head == NULL) {
        return;
    }

    struct Elem* current = head;
    struct Elem* temp;

    do {
        temp = current;
        current = current->next;
        free(temp);
    } while (current != head);
}

void insertionSort(struct Elem** head, int n) {
    for (int i = 0; i < n; ++i) {
        int value;
        scanf("%d", &value);

        struct Elem* newElem = createElem(value);
        insertSorted(head, newElem);
    }
}

void printList(struct Elem* head) {
    if (head == NULL) {
        printf("Список пуст\n");
        return;
    }

    struct Elem* current = head;
    do {
        printf("%d ", current->v);
        current = current->next;
    } while (current != head);
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);

    struct Elem* head = NULL;
    insertionSort(&head, n);
    printList(head);

    freeList(head);

    return 0;
}