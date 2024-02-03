#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *my_strdup(const char *str) {
    size_t len = strlen(str) + 1;
    char *dup = malloc(len);
    
    if (dup != NULL) {
        strcpy(dup, str);
    }
    
    return dup;
}

struct Elem {
    struct Elem *next;
    char *word;
};

void swap(struct Elem *a, struct Elem *b) {
    char *temp = a->word;
    a->word = b->word;
    b->word = temp;
}

int compare(struct Elem *a, struct Elem *b) {
    return strlen(a->word) - strlen(b->word);
}

struct Elem *bsort(struct Elem *list) {
    if (list == NULL || list->next == NULL) {
        return list;
    }

    int swapped;
    struct Elem *ptr1;
    struct Elem *lptr = NULL;

    do {
        swapped = 0;
        ptr1 = list;

        while (ptr1->next != lptr) {
            if (compare(ptr1, ptr1->next) > 0) {
                swap(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);

    return list;
}

int main() {
    char input[1000];
    fgets(input, sizeof(input), stdin);

    struct Elem *head = NULL;
    struct Elem *tail = NULL;

    char *token = strtok(input, " \n");

    while (token != NULL) {
        struct Elem *newElem = (struct Elem *)malloc(sizeof(struct Elem));
        newElem->word = my_strdup(token);
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

    struct Elem *sortedList = bsort(head);

    struct Elem *current = sortedList;
    while (current != NULL) {
        printf("%s ", current->word);
        current = current->next;
    }

    current = sortedList;
    while (current != NULL) {
        struct Elem *temp = current;
        current = current->next;
        free(temp->word);
        free(temp);
    }

    return 0;
}