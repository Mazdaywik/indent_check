#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Elem {
    struct Elem *next;
    char *word;
};
struct Elem *bsort(struct Elem *list) {
    int check = 0;
    char *temp;
    struct Elem *current = NULL, *border = NULL, *last = NULL;
    if (list == NULL) {
        return NULL;
    }
    do {
        check = 0;
        current = list;
        while (current->next != border) {
            if (strlen(current->word) > strlen(current->next->word)) {
                temp = current->word;
                current->word = current->next->word;
                current->next->word = temp;
                check = 1;
            }
            current = current->next;
        }
        border = current;
    }
    while (check);
    return list;
}
void FreeList(struct Elem *list)
{
    struct Elem *current = list;
    while (current != NULL) {
        struct Elem *temp = current;
        current = current->next;
        free(temp);
    }
}
int main() {
    char sentence[1001];
    fgets(sentence, 1001, stdin);
    struct Elem *list = NULL, *prev = NULL;
    char *token = strtok(sentence, " ");
    while (token != NULL) {
        if (strcmp(token, "\n") == 0) break;
        if (token[strlen(token) - 1] == '\n') token = strtok(token, "\n");
        struct Elem *newElem = (struct Elem *)malloc(sizeof(struct Elem));
        newElem->word = token;
        newElem->next = NULL;
        if (list == NULL) {
            list = newElem;
            prev = newElem;
        } 
        else {
            prev->next = newElem;
            prev = newElem;
        }
        token = strtok(NULL, " ");
    }
    list = bsort(list);
    struct Elem *current = list;
    while (current != NULL) {
        printf("%s ", current->word);
        current = current->next;
    }
    FreeList(list);
    return 0;
}