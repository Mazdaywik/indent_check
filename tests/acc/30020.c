#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

struct List{
    int *span;
    int k;
    char *v;
    struct List **next;
};

void Skip(struct List *list, int m, int k, struct List **p){
    int i = m - 1;
    while(i >= 0){
        while(list->next[i] && list->next[i]->k < k){
            list = list->next[i];
        }
        p[i] = list;
        i -= 1;
    }
}

void Init(struct List *list, int m){
    struct List **l = calloc(m, sizeof(struct List*));
    int *span = calloc(m, sizeof(int));
    list->span = span;
    list->next = l;
    list->k = INT_MIN;
    list->v = NULL;
}

int Rank(struct List *l, int m, int k){
    if(k == INT_MIN) return -1;
    int index = 0;
    int i = m - 1;
    while(i >= 0){
        while(l->next[i] && l->next[i]->k < k){
            index += l->span[i];
            l = l->next[i];
        }
        i -= 1;
    }
    return index;
}

struct List *Succ(struct List *x){
    struct List *y = x->next[0];
    return x->next[0];
}

struct List* skiplist_make() {
    struct List* new = malloc(sizeof(struct List));
    new->next = calloc(17, sizeof(struct List*));
    new->span = calloc(17, sizeof(int));
    new->k = INT_MIN;
    new->v = NULL;
    return new;
}

void Insert(struct List *list, int m, int k, char *v){
    struct List *p[m];
    Skip(list, m, k, p);
    struct List *x = calloc(1, sizeof(struct List));
    Init(x, m);
    x->k = k;
    x->v = v;
    int r_x = Rank(list, m, p[0]->k) + 1;
    int r = (rand() % 1000000) * 2;
    int i = 0;
    while(i < m && r%2 == 0){
        x->next[i] = p[i]->next[i];
        p[i]->next[i] = x;
        int rank = r_x - Rank(list, m, p[i]->k);
        x->span[i] = p[i]->span[i] + 1 - rank;
        p[i]->span[i] = rank;
        r = r / 2;
        i += 1;
    }
    while(i < m){
        p[i]->span[i] += 1;
        i += 1;
    }
}

void Delete(struct List *list, int m, int k){
    struct List *p[m];
    Skip(list, m, k, p);
    struct List *x = Succ(p[0]);
    int i = 0;
    while(i < m && p[i]->next[i] == x){
        p[i]->next[i] = x->next[i];
        p[i]->span[i] += x->span[i] - 1;
        i += 1;
    }
    while(i < m){
        p[i]->span[i] -= 1;
        i += 1;
    }
    free(x->span);
    free(x->next);
    free(x->v);
    free(x);
}

char *Lookup(struct List *list, int m, int k){
    struct List *p[m];
    Skip(list, m, k, p);
    struct List *x = Succ(p[0]);
    char *v = x->v;
    return v;
}


int main(int args, char **argv){
    int n = 0;
    scanf("%d", &n);
    struct List *l = calloc(1, sizeof(struct List));
    int m = 17;
    Init(l, m);
    // fgets(command, 5, stdin);
    char command[7];
    do{
        scanf("%s", command);
        if(strcmp(command, "INSERT") == 0){
            int k = 0;
            char *v = calloc(1001, sizeof(char));
            scanf("%d", &k);
            scanf("%s", v);
            Insert(l, m, k, v);
        }
        else if(strcmp(command, "LOOKUP") == 0){
            int k = 0;
            scanf("%d", &k);
            char *v = Lookup(l, m ,k);
            printf("%s\n", v);
        }
        else if(strcmp(command, "DELETE") == 0){
            int k = 0;
            scanf("%d", &k);
            Delete(l, m, k);
        }
        else if(strcmp(command, "RANK") == 0){
            int k = 0;
            scanf("%d", &k);
            int rank = Rank(l, m, k);
            printf("%d\n", rank);
        }
    }while(strcmp(command, "END") != 0);
    while(l != NULL){
        free(l->span);
        struct List *temp = l->next[0];
        free(l->next);
        free(l->v);
        free(l);
        l = temp;
    }
    return 0;
}
