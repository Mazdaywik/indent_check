#include <stdio.h>
#include <stdlib.h>

struct Elem {
    struct Elem *prev, *next;
    int v;
};

void insert(struct Elem* list, struct Elem* new_elem) {
    struct Elem* current = list;
    while (current->next != list && current->next->v < new_elem->v) {
        current = current->next;
    }
    new_elem->next = current->next;
    new_elem->prev = current;
    current->next->prev = new_elem;
    current->next = new_elem;

}

void listisort(struct Elem* list, int n) {
    struct Elem* current = list->next;
    int i;
    for (i = 1; i < n; i++) {
        struct Elem* temp = current;
        current = current->next;
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        insert(list, temp);
    }
}

int main() {
    int n, value;
    struct Elem* list = (struct Elem*)malloc(sizeof(struct Elem));
    list->prev = list->next = list;
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        struct Elem* new_elem = (struct Elem*)malloc(sizeof(struct Elem));
        new_elem->v = value;
        insert(list, new_elem);
    }

    listisort(list, n);

    struct Elem* current = list->next;
    while (current != list) {
        printf("%d ", current->v);
        current = current->next;
    }
    printf("\n");

    current = list->next;
    while (current != list) {
        struct Elem* temp = current;
        current = current->next;
        free(temp);
    }
    free(list);

    return 0;
}
