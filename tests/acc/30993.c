#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define new_Elem(name) name = (struct Elem*)malloc(sizeof(struct Elem)) \
    ; name->word = (char *)calloc(150, sizeof(char));
struct Elem {
	struct Elem *next;
	char *word;
};
int getWord(char* str, char* dest, int i){
    memset(dest, 0, strlen(dest));
    int j = 0;
    while (i < strlen(str) && str[i] != ' '){
        dest[j] = str[i];
        j++;
        i++;
    }
    while (i < strlen(str) && str[i] == ' '){
        i++;
    }
    return i;
}
struct Elem *bsort(struct Elem* list){
    int elems_changed = 1;
    struct Elem * current_elem, *next_elem, *prev = 0;
    while (elems_changed){
        elems_changed = 0;
        current_elem = list;
        prev = 0;
        while (current_elem && current_elem->next){
            next_elem = current_elem->next;
            if (strlen(next_elem->word) < strlen(current_elem->word)){
                if (prev){
                    prev->next = next_elem;
                } else {
                    list = next_elem;
                }
                current_elem->next = next_elem->next;
                next_elem->next = current_elem;
                elems_changed = 1;
            }
            prev = current_elem;
            current_elem = current_elem->next;
        }
    }
    return list;
}
int main(){
    struct Elem * begin = new_Elem(begin);
    struct Elem * current_elem = begin, *next_elem;
    char str[2000] = {0};
    int n = 0, i = 0;
    fgets(str, 2000, stdin);
    str[strlen(str) - 1] = '\0';
    i = getWord(str, begin->word, i);
    while (1){
        n++;
        next_elem = new_Elem(next_elem);
        i = getWord(str, next_elem->word, i);
        if (!strlen(next_elem->word)){
            current_elem->next = 0;
            free(next_elem->word);
            free(next_elem);
            next_elem = 0;
            break;
        }
        current_elem->next = next_elem;
        current_elem = next_elem;
    }
    begin = bsort(begin);
    current_elem = begin;
    for (int i = 0; i < n; i++){
        struct Elem *nextElem = current_elem->next;
        printf("%s", current_elem->word);
        if (i != n - 1){
            printf(" ");
        }
        free(current_elem->word);
        free(current_elem);
        current_elem = nextElem;
    }
}