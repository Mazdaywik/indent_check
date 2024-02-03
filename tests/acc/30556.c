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
    int key;
    int val;
};

struct HashTable {
    struct Elem **h;
    int m;
};

void Delete(struct HashTable *map, int i) {
    int key = i;
    i %= (map->m);
    struct Elem *e = map->h[i];
    if (!e){
        return;
    }
    if (e->key == key) {
        map->h[i] = e->next;
        free(e);
    } else {
        while (e->next) {
            struct Elem *enext = e->next;
            if (enext->key == key) {
                e->next = enext->next;
                free(enext);
                break;
            }
            e = e->next;
        }
    }
}

void Assign(struct HashTable *map, int i, int x) {
    int key = i;
    i %= (map->m);
    if (!(map->h[i])) {
        map->h[i] = (struct Elem*) malloc(sizeof(struct Elem));
        map->h[i]->next = 0;
        map->h[i]->key = -1;
    }
    struct Elem *e = map->h[i];
    while (e->next) {
        if (e->key == key) {
            e->val = x;
            return;
        }
        e = e->next;
    }
    e->next = (struct Elem*) malloc(sizeof(struct Elem));
    e->next->next = 0;
    e->next->key = -1;
    e->key = key;
    e->val = x;
}

int At(struct HashTable *map, int i) {
    int key = i;
    i %= (map->m);
    if (!(map->h[i])) {
        map->h[i] = (struct Elem*) malloc(sizeof(struct Elem));
        map->h[i]->next = 0;
        map->h[i]->key = -1;
    }
    struct Elem *e = map->h[i];
    while (e->next) {
        if (e->key == key) {
            return e->val;
        }
        e = e->next;
    }
    return 0;
}

void freee(struct Elem *e) {
    if (e == 0)
        return;
    freee(e->next);
    free(e);
}

int main(){
    int m;
    char com[20];
    scanf("%d", &m);
    struct HashTable map;
    map.m = m;
    map.h = (struct Elem**) malloc(sizeof(struct Elem*) * m);
    memset(map.h, 0, sizeof(struct Elem*) * m);
    while (1) {
        scanf("%s", com);
        if (!strcmp(com, "ASSIGN")) {
            int i, v;
            scanf("%d %d", &i, &v);
            if (v == 0){
                Delete(&map, i);
                continue;
            }
            Assign(&map, i, v);
        }
        else if (!strcmp(com, "AT")) {
            int i;
            scanf("%d", &i);
            int ans = At(&map, i);
            printf("%d\n", ans);
        }
        else if (!strcmp(com, "END")) {
            break;
        }
    }
    for (int i = 0; i < m; ++i) {
        freee(map.h[i]);
    }
    free(map.h);
    return 0;
}