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

struct Elem {
    struct Elem *next;
    char *word;
};

void swap(struct Elem* a, struct Elem* b){
    char* tmp = a->word;
    a->word = b->word;
    b->word = tmp;
}

struct Elem* insert(struct Elem* next, char *s){
    struct Elem *cur = (struct Elem*) malloc(sizeof(struct Elem));
    cur->next = next;
    cur->word = s;
    return cur;
}

struct Elem* bsort(struct Elem *list){
    struct Elem* first = NULL;
    while (first != list) {
        struct Elem *cur = list;
        while (cur->next != first) {
            if (strlen(cur->next->word) < strlen(cur->word)) {
                swap(cur->next, cur);
            }
            cur = cur->next;
        }
        first = cur;
    }
    return list;
}

void free_elem(struct Elem* list) {
    if (list == NULL){
        return;
    }
    free_elem(list->next);
    free(list);
}

char **get_strings(char *s, int *cnt) {
    char **a = NULL;
    char *sub = NULL;
    char c = 'a';
    int s_cnt = 0, c_cnt = 0;
    while (c != '\0') {
        c = *(s++);
        if (c != ' ' && c != '\0') {
            if (c_cnt == 0) {
                sub = (char*) malloc(sizeof(char));
            }
            else {
                sub = (char*) realloc(sub, sizeof(char) * (c_cnt + 1));
            }
            *(sub + c_cnt) = c;
            c_cnt++;
        }
        else if (c_cnt != 0) {
            sub = (char*) realloc(sub, sizeof(char) * (c_cnt + 1));
            sub[c_cnt] = '\0';
            a = (char**) realloc(a, sizeof(char*) * (s_cnt + 1));
            *(a + s_cnt) = (char*) malloc((c_cnt + 1) * sizeof(char));
            for (int i = 0; i <= c_cnt; ++i) {
                (*(a + s_cnt))[i] = sub[i];
            }
            s_cnt += 1;
            c_cnt = 0;
            free(sub);
        }
    }
    *cnt = s_cnt;
    return a;
}

int  main(){
    char *s = (char*) malloc(1001 * sizeof(char));
    char c;
    int ind = 0, cnt = 0;
    scanf("%c", &c);
    while (c != '\0' && c != '\n'){
        s[ind++] = c;
        scanf("%c", &c);
    }
    s[ind] = '\0';

    char **mass = get_strings(s, &cnt);

    struct Elem* list = NULL;
    for (int i = cnt - 1; i >= 0; --i){
        list = insert(list, mass[i]);
    }
    list = bsort(list);
    struct Elem *cur = list;
    while (cur != NULL){
        printf("%s ", cur->word);
        cur = cur->next;
    }
    free_elem(list);
    free(s);
    for (int i = 0; i < cnt; ++i){
        if (mass[i] == NULL){
            continue;
        }
        free(mass[i]);
    }
    free(mass);
    return 0;
}