#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000000

struct Node {
    int key;
    int value;
    struct Node *next;
};

struct Node *hashTable[MAX_SIZE];

int hashFunction(int key, int m) {
    return key % m;
}

int at(int key) {
    int index = hashFunction(key, MAX_SIZE);
    struct Node *current = hashTable[index];
    while (current != NULL) {
        if (current->key == key) {
            return current->value;
        }
        current = current->next;
    }
    return 0;
}

void assign(int key, int value) {
    int index = hashFunction(key, MAX_SIZE);
    struct Node *current = hashTable[index];
    struct Node *prev = NULL;
    while (current != NULL) {
        if (current->key == key) {
            if (value == 0) {
                if (prev == NULL) {
                    hashTable[index] = current->next;
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
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->key = key;
        newNode->value = value;
        newNode->next = hashTable[index];
        hashTable[index] = newNode;
    }
}

void freeHashTable() {
    for (int i = 0; i < MAX_SIZE; i++) {
        struct Node *current = hashTable[i];
        while (current != NULL) {
            struct Node *temp = current;
            current = current->next;
            free(temp);
        }
    }
}

int main() {
    int m;
    scanf("%d", &m);

    char operation[10];
    int i, v;

    while (1) {
        scanf("%s", operation);

        if (strcmp(operation, "END") == 0) {
            break;
        } else if (strcmp(operation, "ASSIGN") == 0) {
            scanf("%d %d", &i, &v);
            assign(i, v);
        } else if (strcmp(operation, "AT") == 0) {
            scanf("%d", &i);
            printf("%d\n", at(i));
        }
    }

    freeHashTable();

    return 0;
}