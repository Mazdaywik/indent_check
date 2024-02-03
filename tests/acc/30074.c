#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Elem {
    struct Elem *next;
    char *word;
};


struct Elem* CreateList(char str[1000][1000], int length) {
    if (length == 0) {
        return NULL;
    }
    struct Elem *first = (struct Elem *)malloc(sizeof(struct Elem));
    first->word = (char *)malloc(strlen(str[0]) + 1);
    strcpy(first->word, str[0]);
    first->next = NULL;
    struct Elem *current = first;

    for (int i = 1; i < length; i++) {
        struct Elem *new_elem = (struct Elem *)malloc(sizeof(struct Elem));
        new_elem->word = (char *)malloc(strlen(str[i]) + 1);
        strcpy(new_elem->word, str[i]);
        new_elem->next = NULL;
        current->next = new_elem;
        current = new_elem;
    }
    return first;
}

int Key(struct Elem *l) {
    int len = strlen(l->word);
    return len;
}

void Swap(struct Elem *list) {
    char *c = list->word;
    list->word = list->next->word;
    list->next->word = c;
}

struct Elem *bsort(struct Elem *list) {
	if (list != NULL) {
	    struct Elem * copy_list = list;
	    while(1) {
		    int is_sorted = 0;
		    struct Elem *sorted_list = copy_list;
		    while(sorted_list->next != NULL) {
			    if (Key(sorted_list) > Key(sorted_list->next)) {
				    Swap(sorted_list);
				    ++is_sorted;
			    }
			    sorted_list = sorted_list->next;
            }
		    if (is_sorted == 0) break;
	    }
    }
	return list;
}

void PrintList(struct Elem *list) {
    while (list != NULL) {
        struct Elem *lst = list;
        printf("%s ", list->word);
        list = list->next;
        free(lst->word);
        free(lst);
    }
}

int main() {
    char sep;
    char str[1000][1000];
    int len = 0;
    do {
        scanf("%s%c", str[len], &sep);
        ++len;
    } while (sep != '\n');
    struct Elem *list = CreateList(str, len);
    struct Elem *sorted = bsort(list);
    PrintList(sorted);
    return 0;
}