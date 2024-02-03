#include <stdio.h>
#include <stdlib.h>

struct pair{
    int next_rank;
    struct Elem *next_elem;
};

struct Elem {
    long long key;
    char *val;
    struct pair span[27];
};

int INSERT(struct Elem *start, int lvl, struct Elem *new){
    int rank = 0;
    if(new->key % (1<<lvl) == 0){
        struct Elem *now = start;
        while (now->span[lvl].next_elem != NULL && now->span[lvl].next_elem->key < new->key) {
            rank += now->span[lvl].next_rank;
            now = now->span[lvl].next_elem;
        }
        if(lvl == 0){
            now->span[lvl].next_rank = 1;
            rank += 1;
            if(now->span[lvl].next_elem != NULL) {
                new->span[lvl].next_elem = now->span[lvl].next_elem;
                new->span[lvl].next_rank = 1;
            }else{
                new->span[lvl].next_elem = NULL;
                new->span[lvl].next_rank = 0;
            }
            now->span[lvl].next_elem = new;
        }else{
            int next_rank = INSERT(now, lvl-1, new);
            if(now->span[lvl].next_elem != NULL) {
                new->span[lvl].next_elem = now->span[lvl].next_elem;
                new->span[lvl].next_rank = now->span[lvl].next_rank - next_rank + 1;
            }else{
                new->span[lvl].next_elem = NULL;
                new->span[lvl].next_rank = 0;
            }
            rank += next_rank;
            now->span[lvl].next_rank = next_rank;
            now->span[lvl].next_elem = new;
        }
    }else {
        struct Elem *now = start;
        while (now->span[lvl].next_elem != NULL && now->span[lvl].next_elem->key < new->key) {
            rank += now->span[lvl].next_rank;
            now = now->span[lvl].next_elem;
        }
        if(now->span[lvl].next_elem != NULL) {
            now->span[lvl].next_rank++;
        }
        rank = INSERT(now, lvl - 1, new);
    }
    return rank;
}
struct Elem *DELETE(struct Elem *start, int lvl, long long key){
    if(key % (1<<lvl) == 0){
        struct Elem *now = start;
        while (now->span[lvl].next_elem != NULL && now->span[lvl].next_elem->key < key) {
            now = now->span[lvl].next_elem;
        }
        if(lvl == 0){
            struct Elem *res = now->span[lvl].next_elem;
            if(now->span[lvl].next_elem->span[lvl].next_elem != NULL) {
                now->span[lvl].next_elem = now->span[lvl].next_elem->span[lvl].next_elem;
                now->span[lvl].next_rank = 1;
            }else{
                now->span[lvl].next_elem = NULL;
                now->span[lvl].next_rank = 0;
            }
            return res;
        }else{
            struct Elem *res = DELETE(now, lvl-1, key);
            if(now->span[lvl].next_elem != res) {
                now->span[lvl].next_rank--;
            }else{
                now->span[lvl].next_elem = res->span[lvl].next_elem;
                now->span[lvl].next_rank += res->span[lvl].next_rank - 1;
            }
            return res;
        }
    }else {
        struct Elem *now = start;
        while (now->span[lvl].next_elem != NULL && now->span[lvl].next_elem->key < key) {
            now = now->span[lvl].next_elem;
        }
        now->span[lvl].next_rank--;
        return DELETE(now, lvl - 1, key);
    }
}
struct Elem *LOOKUP(struct Elem *start, int lvl, long long key){
    if(key % (1<<lvl) == 0){
        struct Elem *now = start;
        while (now->span[lvl].next_elem != NULL && now->span[lvl].next_elem->key < key) {
            now = now->span[lvl].next_elem;
        }
        if(lvl == 0){
            struct Elem *res = now->span[lvl].next_elem;
            return res;
        }else{
            struct Elem *res = LOOKUP(now, lvl-1, key);
            return res;
        }
    }else {
        struct Elem *now = start;
        while (now->span[lvl].next_elem != NULL && now->span[lvl].next_elem->key < key) {
            now = now->span[lvl].next_elem;
        }
        return LOOKUP(now, lvl - 1, key);
    }
}

int RANK(struct Elem *start, int lvl, long long key){
    int rank = 0;
    if(key % (1<<lvl) == 0){
        struct Elem *now = start;
        while (now->span[lvl].next_elem != NULL && now->span[lvl].next_elem->key < key) {
            rank += now->span[lvl].next_rank;
            now = now->span[lvl].next_elem;
        }
        if(lvl == 0){
            return rank + now->span[lvl].next_rank;
        }else{
            rank += RANK(now, lvl-1, key);
            return rank;
        }
    }else {
        struct Elem *now = start;
        while (now->span[lvl].next_elem != NULL && now->span[lvl].next_elem->key < key) {
            rank += now->span[lvl].next_rank;
            now = now->span[lvl].next_elem;
        }
        return rank + RANK(now, lvl - 1, key);
    }
}

int main(int argc, char** argv) {
    struct Elem *start = malloc(sizeof(struct Elem));
    for (int i = 0; i < 27; i++) {
        start->span[i].next_elem = NULL;
        start->span[i].next_rank = 0;
    }
    char command[10];
    long long key;
    scanf("%s", command);
    while (command[0] != 'E'){
        if(command[0] == 'I'){
            char * val = malloc(100 * sizeof(char));
            scanf("%lld%s", &key, val);
            struct Elem *new = malloc(sizeof(struct Elem));
            new->val = val;
            new->key = key;
            for (int i = 0; i < 27; i++) {
                new->span[i].next_elem = NULL;
                new->span[i].next_rank = 0;
            }
            INSERT(start, 26, new);
        }
        if(command[0] == 'D'){
            scanf("%lld", &key);
            struct Elem *now = DELETE(start, 26, key);
            free(now->val);
            free(now);
        }
        if(command[0] == 'L'){
            scanf("%lld", &key);
            struct Elem *now = LOOKUP(start, 26, key);
            printf("%s\n", now->val);
        }
        if(command[0] == 'R'){
            scanf("%lld", &key);
            printf("%d\n", RANK(start, 26, key) - 1);
        }
        scanf("%s", command);
    }

    for(int lvl = 0 ; lvl < 1 ;lvl++) {
        struct Elem *now = start->span[lvl].next_elem;
        while (now != NULL) {
            struct Elem *next = now->span[lvl].next_elem;
            free(now->val);
            free(now);
            now = next;
        }
    }
    free(start);
    return 0;
}
