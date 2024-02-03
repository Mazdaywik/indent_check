#include <string.h>
#include <stdlib.h>
#include <stdio.h>

struct Pair {
    int k;
    int v;
};
struct Node {
    struct Node* next;
    struct Node* prev;
    struct Pair  pair;
};
struct List {
    struct Node *head;
};
struct Map {
    struct List *slots;
    int size;
};

struct Node* create_node(int k, int v){
    struct Node* e = malloc(sizeof(struct Node));
    e->next = NULL;
    e->prev = NULL;
    e->pair.k = k;
    e->pair.v = v;
    return e;
}
void destroy_node(struct Node *e)
{
    free(e);
}
void free_list(struct List *e){
    while (e->head) {
        struct Node *b = e->head;
        e->head = e->head->next;
        destroy_node(b);
    }
}
struct Node* search_node(struct List *l, int k){
    struct Node *e = l->head;
    while (e && e->pair.k != k) {
        e = e->next;
    }
    return e;
}
void assign(struct Map *m, int i, int v) {
    struct List *l = m->slots + i % m->size;
    struct Node *e = search_node(l, i);
    if (e) {
        if (v)
            e->pair.v = v;
        else {
            if (l->head == e)
                l->head = e->next;
            if (e->prev)
                e->prev->next = e->next;
            if (e->next)
                e->next->prev = e->prev;
            free(e);
        }
        return;
    }
    if (!v) {
        return;
    }
    e = create_node(i, v);
    e->next = l->head;
    if (e->next)
        e->next->prev = e;
    l->head = e;
}



int main() {
    int m;
    scanf("%d", &m);

    struct Map map = {
            .slots = calloc(1, m * sizeof(struct List)),
            .size  = m
    };

    while (1) {
        char command[20];
        scanf("%s", command);
        if (!strcmp(command, "END")) {
            break;
        }

        int i;
        scanf("%d", &i);
        if (!strcmp(command, "AT")) {
            struct Node *e = search_node(map.slots + i % map.size, i);
            printf("%d\n", (e ? e->pair.v : 0));
        }
        else if (!strcmp(command, "ASSIGN")) {
            int v;
            scanf("%d", &v);
            assign(&map, i, v);
        }
    }
    for (int i = 0; i < map.size; i++) {
        free_list(map.slots + i);
    }
    free(map.slots);
}