#include <string.h>
#include <stdlib.h>
#include <stdio.h>

struct Elem {
    struct Elem *next;
    char *word;
};

void print(struct Elem* head) {
    printf("%s ", head->word);
    if (head->next != NULL) {
        print(head->next);
    }
}

void clear(struct Elem* head) {
    if (head->next != NULL) {
        clear(head->next);
    }
    free(head);
}

struct Elem* bsort(struct Elem* head) {
    if (head == NULL) {
        return NULL;
    }
    while (1) {
        struct Elem* i = head;
        int ok = 1;
        while (i->next != NULL) {
            if (strlen(i->word) > strlen(i->next->word)) {
                char *tmp = i->word;
                i->word = i->next->word;
                i->next->word = tmp;
                ok = 0;
            }
            i = i->next;
        }
        if (ok) {
            return head;
        }
    }
}

int main() {
    struct Elem* tail = NULL;
    struct Elem* head = NULL;
    char* src = (char*) malloc(1001 * sizeof(char));
    fgets(src, 1001, stdin);
    src[strlen(src) - 1] = '\0';
    int cnt_words = 0;
    int n = strlen(src);
    for (int i = 0; i < n; ) {
        if (src[i] == ' ') {
            i++;
            continue;
        } else {
            int j = i;
            while (j < n && src[j] != ' ') {
                j++;
            }
            cnt_words++;
            i = j;
        }
    }
    char** words = (char**) malloc(cnt_words * sizeof(char*));
    int tmp_word = 0;
    for (int i = 0; i < n; ) {
        if (src[i] == ' ') {
            i++;
            continue;
        } else {
            int j = i;
            while (j < n && src[j] != ' ') {
               j++;
            }
            words[tmp_word] = (char*) malloc((j - i + 1) * sizeof(char));
            j = i;
            while (j < n && src[j] != ' ') {
                words[tmp_word][j - i] = src[j];
                j++;
            }
            words[tmp_word][j - i] = '\0';
            tmp_word++;
            i = j;
        }
    }
    for (int i = 0; i < cnt_words; i++) {
        if (i == 0) {
            tail = malloc(sizeof(struct Elem));
            tail->next = NULL;
            tail->word = words[i];
            head = tail;
        } else {
            struct Elem* new_tail = malloc(sizeof(struct Elem));
            new_tail->next = NULL;
            new_tail->word = words[i];
            tail->next = new_tail;
            tail = new_tail;
        }
    }
    bsort(head);
    print(head);
    for (int i = 0; i < cnt_words; i++) {
        free(words[i]);
    }
    free(words);
    clear(head);
    free(src);
    return 0;
}