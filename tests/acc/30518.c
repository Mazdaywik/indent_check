#include <stdio.h>
#include <stdlib.h>

struct Elem {
    struct Elem* prev, *next;
    int v;
};

void InsertAfter(struct Elem* x, struct Elem* y) {
    y->prev = x;
    y->next = x->next;
    x->next->prev = y;
    x->next = y;
}

void InsertionSort(struct Elem* head) {
    if (head == NULL || head->next == head) {
        return;
    }

    struct Elem* sorted = head->next;
    head->next = head;
    head->prev = head;

    while (sorted != head) {
        struct Elem* curr = sorted;
        sorted = sorted->next;

        struct Elem* pos = head->next;
        while (pos != head && pos->v < curr->v) {
            pos = pos->next;
        }
        InsertAfter(pos->prev, curr);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    struct Elem* list = (struct Elem*)malloc(sizeof(struct Elem));
    list->next = list;
    list->prev = list;

    for (int i = 0; i < n; i++) {
        int v;
        scanf("%d", &v);

        struct Elem* newElem = (struct Elem*)malloc(sizeof(struct Elem));
        newElem->v = v;

        InsertAfter(list->prev, newElem);
    }

    InsertionSort(list);

    struct Elem* curr = list->next;
    while (curr != list) {
        printf("%d ", curr->v);
        struct Elem* temp = curr;
        curr = curr->next;
        free(temp); 
    }

    free(list); 
    return 0;
}
