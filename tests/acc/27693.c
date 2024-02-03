#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Elem {
    struct Elem *next;
    char *word;
};
typedef struct Elem Header;

Header* make_list() {
    Header* first = NULL;
    first = malloc(sizeof(Header));
    Header* first1 = first;
    char *str = malloc(sizeof(char) * 1002);
    fgets(str, 1000, stdin);
    str[strlen(str)-1] = '\0';

    char *list_str = strtok(str, " ");
    if (list_str == NULL) {
        free(first);
        free(str);
        return NULL;
    }

    while (list_str != NULL) {
        char* str1 = malloc(sizeof(char) * (strlen(list_str) + 1));
        strcpy(str1, list_str);
        first->word = str1;
        list_str = strtok(NULL, " ");
        if (list_str != NULL) {
            first->next = malloc(sizeof(struct Elem));
            first = first->next;
        }
    }
    first->next = NULL;
    free(str);
    return first1;
}



struct Elem *bsort(struct Elem *list)
{
    struct Wrapper {
        struct Elem *list;
        struct Wrapper* next;
        int length;
    };
    if ((list == NULL) || (list->next == NULL)){
        return list;
    }
    struct Wrapper* first = malloc(sizeof(struct Wrapper));
    first->list = list;
    first->length = strlen(list->word);
    first->next = NULL;
    struct Wrapper* it = first;
    while (list->next != NULL) {
        list = list->next;
        it->next = malloc(sizeof(struct Wrapper));
        it = it->next;
        it->length = strlen(list->word);
        it->list = list;
        it->next = NULL;
    }

    struct Wrapper* a = first;
    int swap = 1;
    while (swap != 0) {
        swap = 0;
        while (a->next != NULL) {
            if (a->length > a->next->length) {
                int len = a->length;
                struct Elem* list1 = a->list;
                a->length = a->next->length;
                a->list = a->next->list;
                a->next->length = len;
                a->next->list = list1;
                swap = 1;
            }
            a = a->next;
        }
    a = first;
    }
    it = first;
    list = first->list;
    while (it->next != NULL) {
        it->list->next = it->next->list;
        struct Wrapper* dop = it->next;
        free(it);
        it = dop;
    }
    it->list->next = NULL;
    free(it);
    return list;
}

void free_list(struct Elem* first) {
    while (first != NULL) {
        struct Elem* dop = first->next;
        free(first->word);
        free(first);
        first = dop;
    }

}

void print_list(Header* first) {
    while (first != NULL) {
        printf("%s ", first->word);
        first = first->next;
    }
}


int main() {
    Header* first = make_list();
    first = bsort(first);
    print_list(first);
    free_list(first);
    return 0;
}