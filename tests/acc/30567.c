#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000000000

typedef struct Node {
    int key;
    int value;
    struct Node* next;
} Node;

typedef struct HashTable {
    int size;
    Node** buckets;
} HashTable;

int hash(int key, int size) {
    return key % size;
}

Node* createNode(int key, int value) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->key = key;
    node->value = value;
    node->next = NULL;
    return node;
}

HashTable* createHashTable(int size) {
    HashTable* table = (HashTable*) malloc(sizeof(HashTable));
    table->size = size;
    table->buckets = (Node**) malloc(size * sizeof(Node*));
    for (int i = 0; i < size; i++) {
        table->buckets[i] = NULL;
    }
    return table;
}

void assign(HashTable* table, int key, int value) {
    int index = hash(key, table->size);
    Node* node = table->buckets[index];
    while (node != NULL) {
        if (node->key == key) {
            node->value = value;
            return;
        }
        node = node->next;
    }
    Node* newNode = createNode(key, value);
    newNode->next = table->buckets[index];
    table->buckets[index] = newNode;
}

int at(HashTable* table, int key) {
    int index = hash(key, table->size);
    Node* node = table->buckets[index];
    while (node != NULL) {
        if (node->key == key) {
            return node->value;
        }
        node = node->next;
    }
    return 0;
}

void freeHashTable(HashTable* table) {
    for (int i = 0; i < table->size; i++) {
        Node* node = table->buckets[i];
        while (node != NULL) {
            Node* next = node->next;
            free(node);
            node = next;
        }
    }
    free(table->buckets);
    free(table);
}

int main() {
    int m;
    scanf("%d", &m);

    HashTable* table = createHashTable(m);

    while (1) {
        int key, value;
        char command[10];
        scanf("%s", command);
        if (command[1] == 'S') {
            scanf("%d %d", &key, &value);
            assign(table, key, value);
        } else if (command[1] == 'T') {
            scanf("%d", &key);
            int result = at(table, key);
            printf("%d ", result);
        } else if (command[0] == 'E') {
            break;
        }
    }

    freeHashTable(table);

    return 0;
}