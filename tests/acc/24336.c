#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Elem {
    struct Elem *next;
    char *word;
};

struct Elem *bsort(struct Elem *list)
{
    struct Elem *now = list;
    int count = 0;
    while (now != NULL && now->next != NULL){
        if(strlen(now->word) > strlen(now->next->word)) {
            char *temp = now->word;
            now->word = now->next->word;
            now->next->word = temp;
            count++;
        }
        now = now->next;
    }
    return count ? bsort(list) : list;
}

int main(int argc, char** argv) {
    int n;
    scanf("%d", &n);
    char *s = calloc(1000, sizeof(char));
    gets(s);
    struct Elem *start = malloc(sizeof(struct Elem));
    struct Elem *now = start;
    char *word;
    int wasSpace = 1, indS;
    for(int i = 0 ; s[i] != '\n' && s[i] != '\0'; i++){
        if(wasSpace && s[i]!=' '){
            wasSpace = 0;
            word = calloc(1000, sizeof(char));
            indS = 0;
        }
        if(!wasSpace && s[i] == ' '){
            wasSpace = 1;
            struct Elem *new = malloc(sizeof(struct Elem));
            new->next = now->next;
            now->next = new;
            now = new;
            word[indS] = '\0';
            now->word = word;
        }
        if(!wasSpace && s[i] != ' '){
            word[indS++] = s[i];
        }
    }
    if(!wasSpace){
        struct Elem *new = malloc(sizeof(struct Elem));
        new->next = now->next;
        now->next = new;
        now = new;
        word[indS] = '\0';
        now->word = word;
    }
    now->next = NULL;
    start->next = bsort(start->next);
    struct Elem *nowNext;
    for(now = start->next ; now != NULL; now = nowNext){
        nowNext = now->next;
        printf("%s ", now->word);
        free(now->word);
        free(now);
    }
    free(start);
    free(s);
    return 0;
}

