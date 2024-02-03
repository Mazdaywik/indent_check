#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool is_my_list = false;
int n = 0;

struct Elem {
    struct Elem *next;
    char *word;
};

int count(struct Elem *list){
    int n = 0;
    if(is_my_list){
        for(struct Elem *p = list; p->word != NULL; p = p->next){
            n += 1;
        }
    }
    else{
        for(struct Elem *p = list; p != NULL; p = p->next){
            n += 1;
        }
    }
    return n;
}

void *InitSingleLinkedList(struct Elem *e){
    e->next = NULL;
    e->word = NULL;
    return e;
}

void *InsertAfter(struct Elem *list, struct Elem *e, char *word){
    e->word = word;
    list->next = e;
    return list;
}

struct Elem *bsort(struct Elem *list)
{
    if(list == NULL) return 0;
    struct Elem *point;
    int n = count(list);
    while(true){
        point = list;
        int i = 0;
        while(i < n - 1){
            int nextW_length = strlen(point->next->word);
            int W_length = strlen(point->word);
            if(nextW_length < W_length){
                char *temp = point->word;
                point->word = point->next->word;
                point->next->word = temp;
            }
            point = point->next;
            i++;
        }
        n --;
        if(n == 0) break;
    }
    return list;
}

int main(int args, char **argv){
    is_my_list = true;
    char buf[1001];
    fgets(buf, sizeof(buf), stdin);
    const char *seps = " \t\r\n\f\v";
    char *p = strtok(buf, seps);
    struct Elem *list = malloc(sizeof(struct Elem));
    InitSingleLinkedList(list);
    struct Elem *point = list;
    if(p != NULL){
        list->word = p;
    }
    struct Elem *prev = list;
    while(p = strtok(NULL, seps)){
        n += 1;
        struct Elem *e = malloc(sizeof(struct Elem));
        list = InsertAfter(prev, e, p);
        prev = e;
    }
    struct Elem *e = malloc(sizeof(struct Elem));
    list = InsertAfter(prev, e, NULL);
    struct Elem *sorted = bsort(point);
    for(int i = 0; i < n + 1; i++){
        printf("%s ", sorted->word);
        struct Elem *trash = sorted;
        sorted = sorted->next;
        free(trash);
    }
    free(e);
    return 0;
}