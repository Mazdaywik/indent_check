#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Elem {
    struct Elem *next;
    char *word;
} Elem;

Elem *createNewElem(const char *word) {
    Elem *newElem = (Elem *)malloc(sizeof(Elem));
    newElem->word = (char *)malloc(strlen(word) + 1);
    strcpy(newElem->word, word);
    newElem->next = NULL;

    return newElem;
}

Elem *bsort(Elem *list) {
    int swapped;
    Elem *current;
    Elem *last_sorted = NULL;

    if (list == NULL) {
        return NULL;
    }

    do {
        swapped = 0;
        current = list;

        while (current->next != last_sorted) {
            if (strlen(current->word) > strlen(current->next->word)) {
                char *temp = current->word;
                current->word = current->next->word;
                current->next->word = temp;
                swapped = 1;
            }
            current = current->next;
        }
        last_sorted = current;
    } while (swapped);

    return list;
}

int main() {
    char sentence[1000];
    gets(sentence);

    Elem *list = NULL, *tail = NULL;
    char cur_word[1000];
    int w_index = 0;

    for (int i = 0; sentence[i] != '\0'; ++i) {
        if (sentence[i] == ' ' || sentence[i] == '\n') {
            if (w_index > 0) {
                cur_word[w_index] = '\0';
                Elem *newElem = createNewElem(cur_word);

                if (tail) {
                    tail->next = newElem;
                } else {
                    list = newElem;
                }
                tail = newElem;

                w_index = 0;
            }
        } else {
            cur_word[w_index++] = sentence[i];
        }
    }

    if (w_index > 0) {
        cur_word[w_index] = '\0';
        Elem *newElem = createNewElem(cur_word);

        if (tail) {
            tail->next = newElem;
        } else {
            list = newElem;
        }
    }

    list = bsort(list);

    while (list != NULL) {
        printf("%s ", list->word);
        Elem *temp = list;
        list = list->next;
        free(temp->word);
        free(temp);
    }
    printf("\n");

    return 0;
}
