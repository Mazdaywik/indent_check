#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    struct Node *next[26];
    int isWord;
    int count;
    int isroot;
};

int searchCount(struct Node *start, char *s){
    if(start == NULL)
        return 0;
    if(s[0] == '\n' || s[0] == '\0')
        return start->count;
    return searchCount(start->next[s[0] - 'a'], s + 1);
}

int search(struct Node *start, char *s){
    if(s[0] == '\n' || s[0] == '\0')
        return start->isWord;
    if(start->next[s[0] - 'a'] == NULL)
        return 0;
    return search(start->next[s[0] - 'a'], s + 1);
}

void insert(struct Node *start, char *s){
    if(s[0] == '\n' || s[0] == '\0') {
        start->count++;
        start->isWord = 1;
        return;
    }
    if(start->next[s[0] - 'a'] == NULL)
        start->next[s[0] - 'a'] = calloc(1, sizeof(struct Node));
    start->count++;
    insert(start->next[s[0] - 'a'], s + 1);
}

struct Node *delete(struct Node *start, char *s){
    if(s[0] == '\n' || s[0] == '\0' || start->next[s[0] - 'a'] == NULL) {
        start->count--;
        start->isWord = 0;
        if(start->count == 0 && !start->isroot){
            free(start);
            return NULL;
        }
        return start;
    }
    start->count--;
    start->next[s[0] - 'a'] = delete(start->next[s[0] - 'a'], s + 1);
    if(start->count == 0 && !start->isroot){
        free(start);
        return NULL;
    }
    return start;
}

void cleanup(struct Node *start) {
    if (start != NULL) {
        for (int i = 0; i < 26; i++) {
            cleanup(start->next[i]);
        }
        free(start);
    }
}

int main() {
    struct Node *start = calloc(1, sizeof(struct Node));
    start->isroot = 1;
    int m;
    scanf("%d", &m);
    while (1) {
        char action[19];
        char s[100000];
        scanf("%s", action);
        if (strcmp(action, "INSERT") == 0){
            scanf("%s", s);
            if(!search(start, s))
                insert(start, s);
        }
        else if (strcmp(action, "PREFIX") == 0) {
            scanf("%s", s);
            printf("%d\n", searchCount(start, s));
        }
        else if (strcmp(action, "DELETE") == 0) {
            scanf("%s", s);
            delete(start, s);
        }
        else if (strcmp(action, "END") == 0) {
            break;
        }
    }
    cleanup(start);
    return 0;
}