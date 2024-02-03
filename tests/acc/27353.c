#include <stdio.h>
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <wchar.h>

#define min(a,b) ((a) < (b) ? (a) : (b))
//#define max(a, b) ((a) < (b) ? (b) : (a))
#define maxsz (int)1e6 + 1000
#define inf (int)1e9

typedef long long ll;

int maxx(int x, int y) {
    return x < y ? y : x;
}

struct Node {
    struct Node* next[26];
    int cnt;
    int term;
};

void create(struct Node* t){
    for (int i = 0; i < 26; ++i){
        t->next[i] = NULL;
    }
    t->cnt = 0;
    t->term = 0;
}

int insert(struct Node *t, char *s) {
    struct Node* cur = t;
    int len = strlen(s);
    for (int i = 0; i < len; ++i){
        int c = s[i] - 'a';
        if (cur->next[c] == NULL){
            cur->next[c] = (struct Node *) malloc(sizeof(struct Node));
            create(cur->next[c]);
        }
        cur = cur->next[c];
        cur->cnt += 1;
    }
    cur->term = 1;
}

void delete(struct Node *t, char *s){
    struct Node *cur = t;
    int len = strlen(s);
    for (int i = 0; i < len; ++i){
        int c = s[i] - 'a';
        if (cur->next[c] != NULL){
            cur->cnt -= 1;
            cur = cur->next[c];
        }
        else{
            return;
        }
    }
    cur->cnt -= 1;
    cur->term = 0;
}

int pr_count(struct Node *t, char *s){
    struct Node *cur = t;
    int cnt = 0, len = strlen(s);
    for (int i = 0; i < len; ++i){
        int c = s[i] - 'a';
        if (cur->next[c] == NULL){
            return 0;
        }
        cur = cur->next[c];
    }
    return cur->cnt;
}

int find(struct Node* t, char*s){
    struct Node* cur = t;
    int len = strlen(s);
    for (int i = 0; i < len; ++i){
        int c = s[i] - 'a';
        if (cur->next[c] == NULL){
            return 0;
        }
        cur = cur->next[c];
    }
    return cur->term;
}

void free_node(struct Node *t) {
    for (int i = 0; i < 26; ++i) {
        if (t->next[i]) {
            free_node(t->next[i]);
        }
    }
    free(t);
}

int main(){
    char com[10];
    struct Node *t = (struct Node*) malloc(sizeof(struct Node));
    create(t);
    while(1){
        scanf("%s", com);
        if (!strcmp(com, "INSERT")) {
            char s[100001];
            scanf("%s", s);
            if (!find(t, s)) {
                insert(t, s);
            }
        }
        else if (!strcmp(com, "DELETE")) {
            char s[100001];
            scanf("%s", s);
            if (find(t, s)) {
                delete(t, s);
            }
        }
        else if (!strcmp(com, "PREFIX")) {
            char s[100001];
            scanf("%s", s);
            int ans = pr_count(t, s);
            printf("%d ", ans);
        }
        else if (!strcmp(com, "END")) {
            break;
        }
    }
    free_node(t);
    return 0;
}