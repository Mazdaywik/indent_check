#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Elem {
    struct Elem* next;
    char* word;
};

struct Elem* bsort(struct Elem* list);

int main() {
    char input[1000];
    fgets(input, sizeof(input), stdin);

    struct Elem* head = NULL;
    struct Elem* tail = NULL;

    char* token = strtok(input, " \n");
    while (token != NULL) {
        struct Elem* newElem = (struct Elem*)malloc(sizeof(struct Elem));
        newElem->word = (char*)malloc(strlen(token) + 1);
        strcpy(newElem->word, token);
        newElem->next = NULL;

        if (head == NULL) {
            head = newElem;
            tail = newElem;
        }
        else {
            tail->next = newElem;
            tail = newElem;
        }

        token = strtok(NULL, " \n");
    }

    head = bsort(head);

    struct Elem* current = head;
    while (current != NULL) {
        printf("%s ", current->word);
        struct Elem* temp = current;
        current = current->next;
        free(temp->word);
        free(temp);
    }

    return 0;
}

struct Elem* bsort(struct Elem* list) {
    int swapped;
    struct Elem* ptr1;
    struct Elem* lptr = NULL;

    if (list == NULL)
        return NULL;

    do {
        swapped = 0;
        ptr1 = list;

        while (ptr1->next != lptr) {
            if (strlen(ptr1->word) > strlen(ptr1->next->word)) {
                char* temp = ptr1->word;
                ptr1->word = ptr1->next->word;
                ptr1->next->word = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);

    return list;
}