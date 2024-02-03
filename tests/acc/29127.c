#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct elem {
    struct elem *next;
    char *word;
};


struct elem *bsort(struct elem *list)
{
    if (list == NULL) return NULL;
    int inversion = 1;
    while (inversion != 0){
        inversion = 0;
        struct elem *cur = list;
        while(cur->next != NULL){
            if(strlen(cur->word) > strlen(cur->next->word)){
                char *s = cur->word;
                cur->word = cur->next->word;
                cur->next->word = s;
                inversion = 1;
            }
            cur = cur->next;
        }
    }
    return list;
}

int main(int argc, char** argv)
{
    struct elem *list = NULL, *current = NULL;
    char words[1001], c, n;
    int v=0;
    while((c = getchar()) != '\n'){
        n = getchar();
        if(c != ' ') words[v++] = c;
        if(n == '\n' && v != 0 || v != 0 && c == ' '){
            words[v] = '\0';
            struct elem *ins = (struct elem*)calloc(1, sizeof(struct elem));
            ins->word = (char*)calloc(v+1, sizeof(char));
            ins->next = NULL;
            strcpy(ins->word, words);
            if(list == NULL) {
                list = ins;
                current = ins;
            }
            else {
                current->next = ins;
                current = ins;
            }
            v = 0;
        }
        ungetc(n, stdin);
    }
    struct elem *nextel = bsort(list), *nextnextel;
    while(nextel != NULL){
        printf("%s ", nextel->word);
        struct elem *clean = nextel;
        nextel = nextel->next;
        free(clean->word);
        free(clean);
    }
    return 0;
}