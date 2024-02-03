#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Elem {
    struct Elem *next;
    char *word;
};


struct Elem *bsort(struct Elem *list)
{
    struct Elem *tek = list;
    int count = 0;
    while (tek != NULL&&tek->next!=NULL){
        if(strlen(tek->word) > strlen(tek->next->word)){
            char *temp = tek->word;
            tek->word = tek->next->word;
            tek->next->word = temp;
            count++;
        }
        tek = tek->next;
    }
    if(count == 0)
        return list;
    return bsort(list);
}

char *next(){
    char *w = calloc(1000, sizeof(char ));
    int i = 0;
    char c = getc(stdin);
    while (c==' ')
        c = getc(stdin);
    while (c != '\n' && c!='\0' && c!=' '){
        w[i++] = c;
        c = getc(stdin);
    }
    if (strcmp(w, "") == 0)
        return w;
    if(c=='\0'||c=='\n')
        w[i] = 'B';
    else
        w[i] = 'C';
    return w;
}

int main(){
    char *w = next();
    int t = 0;
    struct Elem *root = NULL;
    struct Elem *finish = root;
    for(int i = 0; strcmp(w, "") != 0; i++) {
        if(w[strlen(w)-1] == 'B'){
            t = 1;
        }
        w[strlen(w)-1] = '\0';
        struct Elem *newElement = malloc(sizeof(struct Elem));
        newElement->next = NULL;
        newElement->word = w;
        if(finish != NULL)
            finish->next = newElement;
        else
            root = newElement;
        finish = newElement;
        if(t)
            break;
        w = next();
    }
    if(strcmp(w, "") == 0)
        free(w);
    root = bsort(root);
    struct Elem*nw = root;
    while (nw!=NULL){
        struct Elem *next = nw->next;
        printf("%s ", nw->word);
        free(nw->word);
        free(nw);
        nw = next;
    }
    return 0;
}

