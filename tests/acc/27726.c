#include <stdio.h>
#include <stdlib.h>
struct Elem {
    struct Elem *prev, *next;
    int v;
};
void ListInsert(struct Elem *head, int x) {
    struct Elem *newElem;
    newElem = malloc(sizeof(struct Elem));
    newElem->v = x;
    struct Elem *current = head->next;
    while ((current != head) && (current->v < x)) {
        current = current->next;
    }
    newElem->prev = current->prev;
    newElem->next = current;
    current->prev->next = newElem;
    current->prev = newElem;
}
void PrintList(struct Elem *head) {
    struct Elem *current = head->next;
    while (current != head) {
        printf("%d ", current->v);
        current = current->next;
    }
    printf("\n");
}
void FreeList(struct Elem *head) {
    struct Elem *current = head->next;
    while (current != head) {
        struct Elem *next = current->next;
        free(current);
        current = next;
    }
    free(head);
}
int main() {
    int n, i, x;
    scanf("%d", &n);
    struct Elem *head;
    head = malloc(n * sizeof(struct Elem));
    head->prev = head->next = head;
    for (i = 0; i < n; i++) {
        scanf("%d", &x);
        ListInsert(head, x);
    }
    PrintList(head);
    FreeList(head);
    return 0;
}