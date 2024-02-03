#include <stdio.h>
#include <stdlib.h>

struct Elem {
    struct Elem *prev, *next;
    int v;
};

void insert(struct Elem** head, int val) {
    struct Elem* new_elem = (struct Elem*)malloc(sizeof(struct Elem));
    new_elem->v = val;
    if (*head == NULL) {
        *head = new_elem;
        (*head)->prev = *head;
        (*head)->next = *head;
    } else {
        struct Elem* last = (*head)->prev;
        new_elem->next = *head;
        new_elem->prev = last;
        last->next = new_elem;
        (*head)->prev = new_elem;
    }
}

void printList(struct Elem* head) {
    struct Elem* curr = head;
    do {
        printf("%d ", curr->v);
        curr = curr->next;
    } while (curr != head);
}

void insertionSort(struct Elem** head) {
    if (*head == NULL || (*head)->next == *head) {
        return;
    }
    struct Elem* sorted = *head;
    struct Elem* curr = (*head)->next;

    while (curr != *head) {
        struct Elem* next = curr->next;
        if (curr->v < sorted->v) {
            struct Elem* last = curr->prev;
            last->next = next;
            next->prev = last;

            curr->next = sorted;
            curr->prev = sorted->prev;
            sorted->prev->next = curr;
            sorted->prev = curr;

            sorted = curr;
        } else {
            struct Elem* tr = sorted->next;
            while (tr != sorted && tr->v < curr->v) {
                tr = tr->next;
            }
            if (tr != curr) {
                struct Elem* last = curr->prev;
                last->next = next;
                next->prev = last;

                curr->prev = tr->prev;
                curr->next = tr;
                tr->prev->next = curr;
                tr->prev = curr;
            }
        }
        curr = next;
    }
    *head = sorted;
}

int main() {
    int n;
    scanf("%d", &n);

    struct Elem* list = NULL;

    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        insert(&list, val);
    }

    insertionSort(&list);

    printList(list);

    if (list != NULL) {
        struct Elem* curr = list;
        do {
            struct Elem* temp = curr;
            curr = curr->next;
            free(temp);
        } while (curr != list);
    }

    return 0;
}
