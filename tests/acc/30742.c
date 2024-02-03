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

void rehash(HashTable* table) {
    int newSize = table->size * 2; // Увеличиваем размер в два раза
    Node** newBuckets = (Node**) malloc(newSize * sizeof(Node*));
    for (int i = 0; i < newSize; i++) {
        newBuckets[i] = NULL;
    }

    for (int i = 0; i < table->size; i++) {
        Node* node = table->buckets[i];
        while (node != NULL) {
            Node* next = node->next;
            int newIndex = hash(node->key, newSize);
            node->next = newBuckets[newIndex];
            newBuckets[newIndex] = node;
            node = next;
        }
    }

    free(table->buckets);
    table->buckets = newBuckets;
    table->size = newSize;
}

void assign(HashTable* table, int key, int value) {
    int index = hash(key, table->size);
    Node* node = table->buckets[index];
    Node* prev = NULL;
    while (node != NULL) {
        if (node->key == key) {
            if (value == 0) {
                if (prev == NULL) {
                    table->buckets[index] = node->next;
                } else {
                    prev->next = node->next;
                }
                free(node);
            } else {
                node->value = value;
            }
            return;
        }
        prev = node;
        node = node->next;
    }
    if (value != 0) {
        Node* existingNode = table->buckets[index];
        while (existingNode != NULL) {
            if (existingNode->key == key) {
                existingNode->value = value;
                return;
            }
            existingNode = existingNode->next;
        }

        Node* newNode = createNode(key, value);
        newNode->next = table->buckets[index];
        table->buckets[index] = newNode;
    }

    int itemCount = 0;
    for (int i = 0; i < table->size; i++) {
        Node* node = table->buckets[i];
        while (node != NULL) {
            itemCount++;
            node = node->next;
        }
    }
    if (itemCount > table->size * 0.7) 
        rehash(table);
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