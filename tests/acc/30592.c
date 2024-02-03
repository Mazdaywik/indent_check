#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct trie {
    int v;
    int word;
    struct trie* arcs[26];
};

typedef struct trie trie_t;

trie_t* make_trie() {
    trie_t* new = malloc(sizeof(trie_t));
    (*new).v = 0;
    (*new).word = 0;
    for (int i = 0; i < 26; ++i) {
        (*new).arcs[i] = NULL;
    }
    return new;
}

char trie_contains(trie_t* trie, char* str) {
    while (*str != '\0') {
        if (!(*trie).arcs[*str - 97]) {
            return 0;
        }
        trie = (*trie).arcs[*str - 97];
        str++;
    }
    return (*trie).word == 1;
}

void trie_insert(trie_t* trie, char* str) {
    (*trie).v++;
    while (*str != '\0') {
        int index = *str - 97;
        if (!(*trie).arcs[index]) {
            (*trie).arcs[index] = make_trie();
        }
        trie = (*trie).arcs[index];
        (*trie).v++;
        str++;
    }
    (*trie).word = 1;
}

void trie_cleanup(trie_t* trie) {
    if (trie) {
        for (int i = 0; i < 26; ++i) {
            trie_cleanup((*trie).arcs[i]);
        }
        free(trie);
    }
}

void trie_delete(trie_t* trie, char* str) {
    (*trie).v--;
    while (*str != '\0') {
        int index = *str - 97;
        trie_t *save_tree = trie;
        trie = ((*trie).arcs[index]);
        (*trie).v--;
        if ((*trie).v == 0) {
            trie_cleanup(trie);
            (*save_tree).arcs[index] = NULL;
            return;
        }
        str++;
    }
    (*trie).word = 0;
}

int trie_prefix(trie_t* trie, char* str) {
    while (*str != '\0') {
        int index = *str - 97;
        trie = (*trie).arcs[index];
        if (!trie) {
            return 0;
        }
        str++;
    }
    return (*trie).v;
}


int ACTIONS_COUNT = 4;
char *ACTIONS[] = {"INSERT", "DELETE", "PREFIX", "END"};

int action_index(char *action)
{
    for(int i = 0; i < ACTIONS_COUNT; i++)
        if(strcmp(action, ACTIONS[i]) == 0) return i;
    return -1;
}

int main() {
    trie_t* trie = make_trie();
    int k = 0;
    while (1 == 1) {
        char* command = malloc(sizeof(char) * 10);
        scanf("%s", command);
        int index = action_index(command);
        char* str = NULL;
        switch(index){
            case 3:
                k = 1;
                break;

            case 0:
                str = malloc(sizeof(char) * 100000);
                scanf("%s", str);
                if (!trie_contains(trie, str)) {
                    trie_insert(trie, str);
                }
                free(str);
                break;
            case 1:
                str = malloc(sizeof(char) * 100000);
                scanf("%s", str);
                if (trie_contains(trie, str)) {
                    trie_delete(trie, str);
                }
                free(str);
                break;
            case 2:
                str = malloc(sizeof(char) * 100000);
                scanf("%s", str);
                printf("%d\n", trie_prefix(trie, str));
                free(str);
                break;
        }
        free(command);
        if (k == 1) break;
    }
    trie_cleanup(trie);
    return 0;
}