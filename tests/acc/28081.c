#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Elem {
    struct Elem *next;
    char *word;
};

struct Elem* InitSingleLinkedList(){
        struct Elem* l = NULL;
        return l;
}

void InsertAfter(struct Elem* x, struct Elem* y){
        struct Elem* z = x->next;
        x->next = y;
        y->next = z;
}

struct Elem* InsertBeforeHead(struct Elem* l, struct Elem* y){
        y->next = l;
        l = y;
        return y;
}

void DisplayList(struct Elem* l){
        struct Elem* x = l;
        while(x != NULL){
                printf("%s ", x->word);
                free(x->word);
                struct Elem* y = x->next;
                free(x);
                x = y;
        }
        printf("\n");
}

void Swap(struct Elem* x, struct Elem* y){
        char* z = x->word;
        x->word = y->word;
        y->word = z;
}

struct Elem* bsort(struct Elem* list){
        if(list == NULL) return list;

        struct Elem* loc = NULL;


        while(list->next != loc){
                struct Elem* cur = list;
                while(cur->next != loc){
                        if(strlen(cur->word) > strlen(cur->next->word)){
                                Swap(cur, cur->next);
                        }
                        cur = cur->next;
                }
                loc = cur;

        }
        return list;
}




int main(){
        struct Elem* l = InitSingleLinkedList();

        char* input[501];
        int i = 0;

        while (scanf("%ms", &input[i]) != EOF) {
                i++;
        }
        while(i > 0){
                i--;
                struct Elem* y = malloc(sizeof(struct Elem));
                y->word = input[i];
                l = InsertBeforeHead(l, y);
        }
        l = bsort(l);
        DisplayList(l);
}