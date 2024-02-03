#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Elem {
    struct Elem *next;
    char *word;
};

void InitSingleLinkedList(struct Elem **l) {
    *l = NULL;
}

void swap(struct Elem *a, struct Elem *b) {
    char *c = a->word;
    a->word = b->word;
    b->word = c;
}

struct Elem* bsort(struct Elem *list) {
    int swapped = !(list == NULL);
    struct Elem *el;
    struct Elem *end_el = NULL;

    while (swapped) {
        swapped = 0;
        el = list;

        while (el->next != end_el) {
            if (strlen(el->word) > strlen(el->next->word)) {
                swap(el,el->next);
                swapped = 1;
            }
            el = el->next;
        }
        end_el = el;
    }

    return list;
}

void FreeList(struct Elem **l) {
    struct Elem *freeElem = *l, *new_freeElem = NULL;
    while (freeElem != NULL) {
        free(freeElem->word);
        new_freeElem = freeElem;
        freeElem = freeElem->next;
        free(new_freeElem);
    }
    *l = NULL;
}

int main() {
    struct Elem *list;
    InitSingleLinkedList(&list);
    char str[1001];
    char c;

    while ((c = getchar()) != '\n') {
        if (c != ' ') {
            ungetc(c, stdin);
            scanf("%s", str);
            int len = strlen(str);
            struct Elem *new_elem = (struct Elem *) malloc(sizeof(struct Elem));
            new_elem->word = (char *) calloc(len + 1, 1);
            new_elem->next = NULL;
            new_elem->word = strcpy(new_elem->word, str);

            if (list == NULL)
                list = new_elem;
            else {
                struct Elem* sortrdList = list;
                while (sortrdList->next != NULL) 
                    sortrdList = sortrdList->next;
                sortrdList->next = new_elem;
            }
        }
    }

    list = bsort(list);

    struct Elem *result = list;
    while (result != NULL) {
        printf("%s%c", result->word, (result->next) ? ' ' : '\n');
        result = result->next;
    }

    FreeList(&list);
    return 0;
}