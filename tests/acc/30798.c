#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Elem {
    struct Elem *next;
    char *word;
};

int compare(struct Elem *a, struct Elem *b)
{
    return strlen(a->word) > strlen(b->word);
}

void swap(struct Elem *a, struct Elem *b)
{
    char *temp = a->word;
    a->word = b->word;
    b->word = temp;
}

struct Elem *bsort(struct Elem *list)
{
    int swapped = (list != NULL);
    struct Elem *el;
    struct Elem *end_el = NULL;

    while (swapped) {
        swapped = 0;
        el = list;

        while (el->next != end_el) {
            if (strlen(el->word) > strlen(el->next->word)) {
                swap(el, el->next);
                swapped = 1;
            }
            el = el->next;
        }
        end_el = el;
    }

    return list;
}

void printList(struct Elem* head) {
    for (struct Elem* el = head; el != NULL; el = el->next) {
        printf("%s ", el->word);
    }
    printf("\n");
}

void freeList(struct Elem* head) {
    while (head != NULL) {
        struct Elem* temp = head;
        head = head->next;
        free(temp->word);
        free(temp);
    }
}

int main()
{
    struct Elem *head = (struct Elem *)malloc(sizeof(struct Elem));
    if (head == NULL) {
        return 1;
    }
    head->next = NULL;

    char str[1001];
    char c;
    int i = 0;

    while ((c = getchar()) != '\n') {
        if (c != ' ') {
            ungetc(c, stdin);
            scanf("%s", str);
            int len = strlen(str);
            struct Elem *el = (struct Elem *)malloc(sizeof(struct Elem));
            if (el == NULL) {
                freeList(head);
                return 1;
            }
            el->word = (char *)calloc(len + 1, sizeof(char));
            if (el->word == NULL) {
                free(el);
                freeList(head);
                return 1;
            }
            strcpy(el->word, str);
            el->next = NULL;

            struct Elem *current = head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = el;
        }
    }

    struct Elem *sortedList = bsort(head->next);

    printList(sortedList);

    freeList(sortedList); 

    free(head);

    return 0;
}