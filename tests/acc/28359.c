#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 1000

struct Elem {
    struct Elem* next;
    char* word;
};

struct Elem* createNode(const char* word) {
    struct Elem* node = (struct Elem*) malloc(sizeof(struct Elem));
    node->word = (char*) malloc((strlen(word) + 1) * sizeof(char));
    strcpy(node->word, word);
    node->next = NULL;
    return node;
};

void deleteList(struct Elem* list) {
    struct Elem* deleted;
    while (list != NULL) {
        deleted = list;
        list = list->next;
        free(deleted->word);
        free(deleted);
    }
};

void printList(struct Elem* list) {
    struct Elem* it;
    for (it = list; it != NULL; it = it->next) {
        printf("%s ", it->word);
    }
    printf("\n");
}

int greater(char* word_one, char* word_two) {
    return strlen(word_one) > strlen(word_two);
}

void swapTwoNextList(struct Elem* it) {
    struct Elem* tail = it->next->next->next;
    struct Elem* elem_one = it->next;
    struct Elem* elem_two = it->next->next;
    it->next = elem_two;
    elem_two->next = elem_one;
    elem_one->next = tail;
}

struct Elem* bsort(struct Elem* list) {
    if (list == NULL || list->next == NULL) {
        return list;
    }

    struct Elem* node = createNode("ficted");
    node->next = list;
    list = node;

    struct Elem* end = NULL, * it;
    int is_swap = 1;

    while (is_swap) {
        is_swap = 0;
        for (it = list; it->next->next != end; it = it->next) {
            if (greater(it->next->word, it->next->next->word)) {
                swapTwoNextList(it);
                is_swap = 1;
            }
        }
        end = it->next;
    }

    node = list;
    list = list->next;
    free(node->word);
    free(node);

    return list;
};

int hasWord(char* line, int* pos) {
    int i;
    for (i = *pos; line[i] == ' ' || line[i] == '\n'; ++i);
    *pos = i;
    return line[i] != '\0';
}

void getWord(char* line, int* pos, char* word) {
    int i, len;
    for (i = *pos; line[i] != ' ' && line[i] != '\n' && line[i] != '\0'; ++i) ;
    len = i - *pos;
    strncpy(word, line + *pos, len);
    word[len] = '\0';
    *pos += len;
}

struct Elem* buildList(char* line) {
    struct Elem* list = NULL, * it = NULL;
    int pos = 0;
    char word[MAXLEN + 5];

    if (!hasWord(line, &pos)) {
        return NULL;
    }
    getWord(line, &pos, word);
    list = createNode(word);
    it = list;
    while (hasWord(line, &pos)) {
        getWord(line, &pos, word);
        it->next = createNode(word);
        it = it->next;
    }
    return list;
};

int main() {
    char buffer[MAXLEN + 5];
    struct Elem* list = NULL;
    if (fgets(buffer, MAXLEN + 5, stdin) == NULL) {
        return 0;
    }
    list = buildList(buffer);
    list = bsort(list);
    printList(list);
    deleteList(list);
    return 0;
}
