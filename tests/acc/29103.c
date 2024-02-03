#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Elem {
    struct Elem *next;
    char *word;
};

void swap(struct Elem *a, struct Elem *b){
    char *temp = a->word;
    a->word = b->word;
    b->word = temp;
}

struct Elem *bsort(struct Elem *list){
    int countSwaps = 1;
    while (list != NULL && list->next != NULL && countSwaps){
        countSwaps = 0;
        struct Elem *step = list;
        while (step->next != NULL){
            if(strlen(step->word) > strlen(step->next->word)) {
                swap(step, step->next);
                countSwaps++;
            }
            step = step->next;
        }
    }
    return list;
}

void free_list(struct Elem *now){
    if(now!=NULL){
        free_list(now->next);
        free(now->word);
        free(now);
    }
}


int main(int argc, char *argv[]) {
    char * str = calloc(1002, sizeof(char));
    gets(str);
    str[strlen(str)] = ' ';
    char *free_s = str;
    struct Elem *root = malloc(sizeof(struct Elem));
    root->next = NULL;
    root->word = malloc(1);
    struct Elem *now = root;
    char *s = calloc(1001, sizeof(char));
    while (str[0]==' ')
        str++;
    while (strlen(str) > 0 && sscanf(str, "%s", s) == 1) {
        struct Elem *next = malloc(sizeof(struct Elem));
        next->word = s;
        next->next = NULL;
        now->next = next;
        now = next;
        s = calloc(1001, sizeof(char));
        str = strchr(str, ' ');
        while (str[0]==' ')
            str++;
    }
    free(free_s);
    free(s);
    struct Elem *sorted = bsort(root->next);
    while (sorted != NULL){
        printf("%s ", sorted->word);
        sorted = sorted->next;
    }
    free_list(root);
    return 0;
}