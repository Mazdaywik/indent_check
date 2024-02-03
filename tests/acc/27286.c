#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Elem {
    struct Elem *next;
    char *word;
};

struct Elem *createElem(char *word) {
    struct Elem *elem = malloc(sizeof(struct Elem));
    elem->next = NULL;
    elem->word = malloc(strlen(word) + 1);
    strcpy(elem->word, word);
    return elem;
}

void insertElem(struct Elem **list, struct Elem *elem) {
    if (*list == NULL) {
        *list = elem;
    } else {
        struct Elem *current = *list;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = elem;
    }
}

void freeList(struct Elem *list) {
    while (list != NULL) {
        struct Elem *temp = list;
        list = list->next;
        free(temp->word);
        free(temp);
    }
}

struct Elem *bsort(struct Elem *list) {
    int swapped = 1;
    while (swapped) {
        swapped = 0;
        struct Elem *current = list;
        struct Elem *prev = NULL;
        while (current != NULL && current->next != NULL) {
            if (strlen(current->word) > strlen(current->next->word)) {
                struct Elem *temp = current->next;
                current->next = temp->next;
                temp->next = current;
                if (prev == NULL) {
                    list = temp;
                } else {
                    prev->next = temp;
                }
                prev = temp;
                swapped = 1;
            } else {
                prev = current;
                current = current->next;
            }
        }
    }
    return list;
}

int main() {
    char sentence[1000];
    fgets(sentence, sizeof(sentence), stdin);

    struct Elem *list = NULL;
    char *word = strtok(sentence, " \n");
    while (word != NULL) {
        struct Elem *elem = createElem(word);
        insertElem(&list, elem);
        word = strtok(NULL, " \n");
    }

    struct Elem *sortedList = bsort(list);

    struct Elem *current = sortedList;
    while (current != NULL) {
        printf("%s ", current->word);
        current = current->next;
    }
    printf("\n");

    freeList(sortedList);

    return 0;
}
