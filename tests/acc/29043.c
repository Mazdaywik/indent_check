#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Element {
    unsigned long long key;
    int value;
    struct Element *next;
} Element;

typedef struct {
    unsigned long long size;
    Element **table;
} SparseArray;

unsigned long long hash(unsigned long long key, unsigned long long size) {
    return (key * key + 1) % size;
}

SparseArray* createSparseArray(unsigned long long size) {
    SparseArray *array = malloc(sizeof(SparseArray));
    array->size = size;
    array->table = malloc(sizeof(Element*) * size);
    for (unsigned long long i = 0; i < size; i++) {
        array->table[i] = NULL;
    }
    return array;
}

void assign(SparseArray *array, unsigned long long key, int value) {
    unsigned long long index = hash(key, array->size);
    Element *current = array->table[index];
    Element *prev = NULL;

    while (current != NULL) {
        if (current->key == key) {
            if (value == 0) {
                if (prev == NULL) {
                    array->table[index] = current->next;
                } else {
                    prev->next = current->next;
                }
                free(current);
            } else {
                current->value = value;
            }
            return;
        }
        prev = current;
        current = current->next;
    }

    if (value != 0) {
        Element *newElement = malloc(sizeof(Element));
        newElement->key = key;
        newElement->value = value;
        newElement->next = array->table[index];
        array->table[index] = newElement;
    }
}

int at(SparseArray *array, unsigned long long key) {
    unsigned long long index = hash(key, array->size);
    Element *current = array->table[index];

    while (current != NULL) {
        if (current->key == key) {
            return current->value;
        }
        current = current->next;
    }
    return 0;
}

void freeSparseArray(SparseArray *array) {
    for (unsigned long long i = 0; i < array->size; i++) {
        Element *current = array->table[i];
        while (current != NULL) {
            Element *temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(array->table);
    free(array);
}

int main() {
    unsigned long long m;
    scanf("%llu", &m);

    SparseArray *array = createSparseArray(m);

    char command[10];
    unsigned long long i;
    int v;

    while (1) {
        scanf("%s", command);
        if (strcmp(command, "ASSIGN") == 0) {
            scanf("%llu %d", &i, &v);
            assign(array, i, v);
        } else if (strcmp(command, "AT") == 0) {
            scanf("%llu", &i);
            printf("%d\n", at(array, i));
        } else if (strcmp(command, "END") == 0) {
            break;
        }
    }

    freeSparseArray(array);
    return 0;
}