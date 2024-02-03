#include <stdio.h>
#include <stdlib.h>

struct Elem {
    int value;
    struct Elem* prev, * next;
};

struct Elem* createElem(int value) {
    struct Elem* elem = (struct Elem*)malloc(sizeof(struct Elem));
    elem->value = value;
    elem->next = NULL;
    elem->prev = NULL;
    return elem;
}

void appendList(struct Elem* list, struct Elem* elem) {
    struct Elem* tail = list->prev;
    tail->next = elem;
    elem->next = list;
    elem->prev = tail;
    list->prev = elem;
}

void printList(struct Elem* list) {
    for (struct Elem* it = list->next; it != list; it = it->next) {
        printf("%d ", it->value);
    }
    printf("\n");
}

void clearList(struct Elem* list) {
    list->prev->next = NULL;
    while (list != NULL) {
        struct Elem* elem = list;
        list = list->next;
        free(elem);
    }
}

void insertionSortList(struct Elem* list) {
    if (list->next == list || list->next->next == list) {
        return;
    }
    struct Elem* elements = list->next;
    list->prev->next = NULL;
    list->next = list->prev = list;
    elements->prev = NULL;

    while (elements != NULL) {
        struct Elem* min_elem = elements;
        for (struct Elem* it = elements->next; it != NULL; it = it->next) {
            if (it->value < min_elem->value) {
                min_elem = it;
            }
        }
        struct Elem* prev = min_elem->prev;
        struct Elem* next = min_elem->next;
        min_elem->next = min_elem->prev = NULL;
        appendList(list, min_elem);
        
        if (prev != NULL) {
            prev->next = next;
        } else {
            elements = next;
        }
        if (next != NULL) {
            next->prev = prev;
        }
    }
}

int main() {
    int size;
    scanf("%d", &size);

    struct Elem* list = createElem(0);
    list->next = list->prev = list;
    for (int i = 0, value; i < size; ++i) {
        scanf("%d", &value);
        struct Elem* elem = createElem(value);
        appendList(list, elem);
    }
    insertionSortList(list);
    printList(list);

    clearList(list);
    return 0;
}
