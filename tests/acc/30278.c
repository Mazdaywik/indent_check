#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Elem {
    struct Elem *next;
    char *word;
};


struct Elem *InitSingleLinkedList() {
    struct Elem *l = (struct Elem *)malloc(sizeof(struct Elem));
    return l;
}

void InsertAfter(struct Elem *x, struct Elem *y){
    struct Elem *z = x->next;
    x->next = y;
    y->next = z;
}

void swap(struct Elem* a, struct Elem* b) {
    char* tmp = a->word;
    a->word = b->word;
    b->word = tmp;
}

struct Elem *bsort(struct Elem *list) {
    struct Elem* lim = NULL;
    while (lim != list) {
        struct Elem* i = list;
        while (i->next != lim) {
            if (strlen(i->next->word) < strlen(i->word))
                swap(i->next, i);
            i = i->next;
        }
        lim = i;
    }
    return list;
}



int main(){
    struct Elem *head = InitSingleLinkedList();
    head->next = NULL;
    struct Elem *tail;
    char *word;
    char str[1000];
    gets(str);
    word = strtok(str, " ");
    head->word = word;
    word = strtok(NULL," ");
    while(word){
        struct Elem *elem = malloc(sizeof(struct Elem));
        elem->word = word;
        if (!head->next)
            head->next = elem;
        else
            tail->next = elem;
        tail = elem;
        word = strtok(NULL," ");
        if(!word)
            tail->next = NULL;
    }
    bsort(head);
    while(head){
        printf("%s ", head->word);
        struct Elem *prev = head;
        head = head->next;
        free(prev);
    }
    return 0;
}