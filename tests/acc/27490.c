#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Elem {
    struct Elem *next;
    char *word;
};

struct Elem *bsort(struct Elem *list) {
    int sorted = 0;
    while (!sorted) {
        sorted = 1;
        struct Elem *ptr = list;
        while (ptr != NULL && ptr->next != NULL) {
            if (strlen(ptr->word) > strlen(ptr->next->word)) {
                char *temp = ptr->word;
                ptr->word = ptr->next->word;
                ptr->next->word = temp;
                sorted = 0;
            }
            ptr = ptr->next;
        }
    }
    return list;
}

int main() {
    struct Elem *head = NULL;
    struct Elem *prev = NULL;
    char str[1000];
    if (fgets(str, sizeof(str), stdin) != NULL) {
        char *token = strtok(str, " \n");
        while (token != NULL) {
            struct Elem *newElem = (struct Elem *)malloc(sizeof(struct Elem));
            newElem->word = malloc(strlen(token) + 1);
			if (newElem->word != NULL) {
				strcpy(newElem->word, token);
			
            newElem->next = NULL;
            if (head == NULL) {
                head = newElem;
            } else {
                prev->next = newElem;
            }
            prev = newElem;}
            token = strtok(NULL, " \n");
        }

        head = bsort(head); 
		
        struct Elem *ptr = head;
        while (ptr != NULL) {
            printf("%s ", ptr->word);
            ptr = ptr->next;
        }


        ptr = head;
		
        while (ptr != NULL) {
            struct Elem *temp = ptr;
            ptr = ptr->next;
            free(temp->word);
            free(temp);
        }
    }
    return 0;
}
