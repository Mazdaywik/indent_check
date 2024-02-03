#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct list_t {
    struct list_t *next;
    long long int i;
    long long int val;
} list_t;

typedef struct {
    list_t **array;
    long long int size;
} disparray;

list_t * make_stack(list_t *prev, long long int i, long long int val) {
    if(val == 0)
        return prev;
    list_t *new;
    new = (list_t *)malloc(sizeof(list_t));
    (*new).i = i;
    (*new).val = val;
    (*new).next = NULL;
    if(prev != NULL){
        prev->next = (struct list_t *) new;
        return prev;
    }
    return new;
}


disparray *make_disparray(){
    disparray *new;
    new = (disparray *)malloc(sizeof(disparray));
    long long int m;
    scanf("%lld", &m);
    new->size = m;
    new->array = calloc(m, sizeof(list_t));
    while (m--)
        new->array[m] = make_stack(NULL, -1, -1);
    return new;
}

void Assign(disparray *d, long long int i, long long int v){
    long long int h = i % d->size;
    list_t *lvlRoot = d->array[h];
    while (lvlRoot->next != NULL && lvlRoot->next->i != i)
        lvlRoot = lvlRoot->next;
    if(lvlRoot->next == NULL){
        make_stack(lvlRoot, i, v);
        return;
    }
    if(v == 0){
        list_t *next_next = lvlRoot->next->next;
        free(lvlRoot->next);
        lvlRoot->next=next_next;
        return;
    }
    lvlRoot->next->val = v;
}

void At(disparray *d, long long int i){
    long long int h = i % d->size;
    list_t *lvlRoot = d->array[h];
    while (lvlRoot->next != NULL && lvlRoot->next->i != i)
        lvlRoot = lvlRoot->next;
    if(lvlRoot->next == NULL)
        printf("0\n");
    else
        printf("%lld\n", lvlRoot->next->val);
}

void cleanup(disparray *d){
    for(int i = 0 ; i < d->size; i++){
        list_t *lvl = d->array[i];
        while (lvl != NULL){
            list_t *next = lvl->next;
            free(lvl);
            lvl = next;
        }
    }
    free(d->array);
    free(d);
}

int main(){
    disparray * di = make_disparray();
    while (1 == 1) {
        char* command;
        scanf("%ms", &command);
        if (strcmp(command, "END") == 0){
            free(command);
            break;
        }
        if (strcmp(command, "ASSIGN") == 0) {
            long long int i, v;
            scanf("%lld%lld", &i, &v);
            Assign(di, i, v);
        }
        else if (strcmp(command, "AT") == 0) {
            long long int i;
            scanf("%lld", &i);
            At(di, i);
        }
        free(command);
    }
    cleanup(di);
}