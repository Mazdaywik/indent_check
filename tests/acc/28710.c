#include <string.h>
#include <stdlib.h>
#include <stdio.h>

struct Pair {
    int k;
    int v;
};
struct Node {
    struct Node* next;
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
struct Node* push_front(struct List *l, int i, int v) {
    struct Node* e = create_node(i, v);
    e->next = l->head;
    l->head = e;
    return e;
}
struct Node* search_node(struct List *l, int k){
    struct Node *e = l->head;
    while (e && e->pair.k != k) {
        e = e->next;
    }
    return e;
}


int main() {
    int m;
    scanf("%d", &m);

    struct Map map = {
        .slots = calloc(1, m * sizeof(void*)),
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
        
        struct Node *e = search_node(map.slots + i % map.size, i);
        if (!strcmp(command, "AT")) {
            printf("%d\n", (e ? e->pair.v : 0));
        }
        else if (!strcmp(command, "ASSIGN")) {
            int v;
            scanf("%d", &v);
            if (e) {
                e->pair.v = v;
            }
            else {
                push_front(map.slots + i % map.size, i, v);
            }
        }
    }
    for (int i = 0; i < map.size; i++) {
        free_list(map.slots + i);
    }
    free(map.slots);
}