#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct elem 
{
    int key, value;
    struct elem* next;
};

struct elem *eleminit()
{
	struct elem *el = (struct elem*)calloc(1, sizeof(struct elem));
	el->key = 0;
	el->value = 0;
	el->next = NULL;
	return el;
}

struct elem **tableinit(int m)
{
	struct elem **spar = (struct elem**)calloc(m, sizeof(struct elem*));
	for (int i = 0; i < m; i++) spar[i] = eleminit();
	return spar;
}

int h(int i, int m) {
    return i % m;
}

void insert(struct elem **spar, int key, int value, int m) 
{
    int hi = h(key, m);
    struct elem *newel = (struct elem*)calloc(1, sizeof(struct elem));
    newel->key = key;
    newel->value = value;
    newel->next = spar[hi];
    spar[hi] = newel;
}

int find(struct elem **spar, int key, int m) 
{
    int hi = h(key, m);
    struct elem* newel = spar[hi];
    while (newel != NULL) {
        if (newel->key == key) return newel->value;
        newel = newel->next;
    }
    return 0;
}

void delete(struct elem **spar, int key, int m) 
{
    int hi = h(key, m);
    struct elem* newel = spar[hi];
    struct elem* prev = NULL;
    while (newel != NULL) {
        if (newel->key == key) {
            if (prev == NULL) spar[hi] = newel->next;
            else prev->next = newel->next;
            free(newel);
            break;
        }
        prev = newel;
        newel = newel->next;
    }
}


void assign(struct elem **spar,int key, int value, int m) {
    int hi = h(key, m);
    struct elem* newel = spar[hi];
    while (newel != NULL) {
        if (newel->key == key) {
            if (value == 0) {
                delete(spar, key, m);
            } else {
                newel->value = value;
            }
            return;
        }
        newel = newel->next;
    }
    if (value != 0) {
        insert(spar, key, value, m);
    }
}



int main() 
{
    int m;
    scanf("%d", &m);
    struct elem **spar = tableinit(m);
    char word[7];
    scanf("%s", word);
    while (strcmp(word, "END") != 0) {
        int i;
        scanf("%d", &i);
        if (strcmp(word, "AT") == 0) printf("%d\n", find(spar, i, m));
        else if (strcmp(word, "ASSIGN") == 0) {
            int v;
            scanf("%d", &v);
            assign(spar, i, v, m);
        }
        scanf("%s", word);
    }
    for (int i = 0; i < m; i++) {
        struct elem *cur = spar[i];
        while (cur != NULL) {
            struct elem *temp = cur;
            cur = cur->next;
            free(temp);
        }
    }
    free(spar);
    return 0;
}