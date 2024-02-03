#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Elem {
    struct Elem *next;
    char *word;
};

struct Elem *createList(char **arr, int i) {
    struct Elem *head = NULL;
    while (i >= 0) {
        struct Elem *newElem = (struct Elem *)malloc(sizeof(struct Elem));
        newElem->word = arr[i];
        newElem->next = head;
        head = newElem;
        i--;
    }
    return head;
}

struct Elem *bsort(struct Elem *list) {
    int swapped = 1, i = 0;
    struct Elem *ptr1, *ptr;
    struct Elem *lptr = NULL;

    if (list == NULL)
        return NULL;

    while (swapped){
        swapped = 0;
        ptr1 = list;
        i = 0;
        while (ptr1->next != lptr) {
            if (strlen(ptr1->word) > strlen(ptr1->next->word)) {
                char *swap_word = ptr1->word;
                ptr1->word = ptr1->next->word;
                ptr1->next->word = swap_word;
                swapped = 1;
                    // ptr = ptr1->next;
            }
            ptr1 = ptr1->next;
        }
    lptr = ptr1;
    }
    return list;
}

int main() {
    char sentence[1000];
    fgets(sentence, sizeof(sentence), stdin);

    sentence[strlen(sentence)-1] = '\0';
    char *word = strtok((char *)sentence, " ");
    char *arr[1000];
    int i = 0;
    while (word != NULL) {
        arr[i] = word;
        i++;
        word = strtok(NULL, " ");
    }
    i--;
    
    struct Elem *list = createList(arr, i);
    list = bsort(list);

    struct Elem* var_for_free;
    while (list) {
        printf("%s ", list->word);
        var_for_free = list;
        list = list->next;
        free(var_for_free);
    }

    return 0;
}

// sdlj sldfjalsdfhj afhlasd hfshf skdfh skdf ksd fdfh sdfnfksd vsjkd s sdhfsouhfkj dsfs