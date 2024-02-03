#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 1001

struct Elem {
    struct Elem *next;
    char *word;
};

struct Elem* InitSingleLinkedList()
{
    return NULL;
}

struct Elem* Insert(struct Elem* list, char *str)
{
    struct Elem *l;
    l = malloc(sizeof(struct Elem));
    l->word = calloc(100, sizeof(char));
    strcpy(l->word, str);
    l->next = list;
    list = NULL;
    return l;
}

int ListEmpty(struct Elem *l)
{
    return (l == NULL);
}

void swap(struct Elem *a, struct Elem *b)
{
    char *word = a->word;
    a->word = b->word;
    b->word = word;
}

struct Elem *bsort(struct Elem *list)
{
    if (ListEmpty(list)) return list;
    struct Elem *i = list;
    while (i != NULL) {
        struct Elem *j = list;
        while(j->next != NULL) {
            if (strlen(j->next->word) < strlen(j->word))
                swap(j, j->next);
            j = j->next;
        }
        i = i->next;
    }
    return list;
}


struct Elem* Words(char *src, struct Elem *list)
{
    char **words;
    words = (char**) calloc(SIZE, sizeof(char*));
    
    int wordCounter = 0;
    int len_word = 0;
    
    int for_word = 1;
    int for_whitespace = 1;
    
    int lense = strlen(src);
    if (src[strlen(src) - 1] == '\n') lense--;
    
    for(int i = 0; i < lense; i++) {
        if (src[i] != ' ') {
            if (for_word == 1) {
                words[wordCounter] = (char*) calloc(SIZE, sizeof(char));
                for_word = 0;
                for_whitespace = 1;
            }
        } else {
            if (for_whitespace == 1) {
                
                words[wordCounter][len_word++] = '\0';
                wordCounter++;
                len_word = 0;
                for_whitespace = 0;
                for_word = 1;
            }
            continue;
        }
        words[wordCounter][len_word] = src[i];
        len_word++;
    }
    
    if (words[wordCounter] != NULL)
        wordCounter++;
    
    for (int i = wordCounter -  1; i >= 0; i--)
        list = Insert(list, words[i]);
    
    for (int i = 0; i < wordCounter; i++) free(words[i]);
    free(words);
    
    return list;
}


int main()
{
    char *str;
    str = (char*) calloc(SIZE, sizeof(char));
    fgets(str, 1001, stdin);
    
    struct Elem* list = InitSingleLinkedList();
    
    list = bsort(Words(str, list));
    
    struct Elem *p;
    while (list) {
        printf("%s ", list->word);
        p = list->next;
        free(list->word);
        free(list);
        list = p;
    }

    free(str);
    return 0;
}
