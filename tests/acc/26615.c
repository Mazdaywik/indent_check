#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TrieNode {
    struct TrieNode* children[26];
    int count;
    int isend;
} TrieNode;

TrieNode* createNode() {
    TrieNode* node = (TrieNode*)malloc(sizeof(TrieNode));
    node->count = 0;
    node->isend = 0;
    for (int i = 0; i < 26; i++) {
        node->children[i] = NULL;
    }
    return node;
}

void insert(TrieNode* current, char* key) {
    int length = strlen(key);
    for (int i = 0; i < length; i++) {
        int index = key[i] - 'a';
        if (current->children[index] == NULL) {
            current->children[index] = createNode();
        }
        current = current->children[index];
        current->count++;
    }
    current->isend = 1;
}

int chek_existence(TrieNode* current, char* key) {
    int length = strlen(key);
    for (int i = 0; i < length; i++) {
        int index = key[i] - 'a';
        if (current->children[index]) {
            current = current->children[index];
        }
        else {
            return 0;
        }
    }
    return current->isend;
    
}

void delete(TrieNode* current, char* key) {
    int length = strlen(key);
    for (int i = 0; i < length; i++) {
        int index = key[i] - 'a';
        if (current->children[index] == NULL) {
            return;
        }
        current = current->children[index];
        current->count--;
    }
    current->isend = 0;
}

int prefixCount(TrieNode* current, char* prefix) {
    int length = strlen(prefix);
    for (int i = 0; i < length; i++) {
        int index = prefix[i] - 'a';
        if (current->children[index] == NULL) {
            return 0;
        }
        current = current->children[index];
    }
    return current->count;
}

void freeTrie(TrieNode* root) {
    if (root) {
        for (int i = 0; i < 26; i++) {
            freeTrie(root->children[i]);
        }
        free(root);
    }
}

int main() {
    TrieNode* root = createNode();

    char operation[10];
    char key[100000];

    while (1) {
        scanf("%s", operation);
        if (strcmp(operation, "INSERT") == 0) {
            scanf("%s", key);
            if (!chek_existence(root, key)) {
                insert(root, key);
            }
        }
        if (strcmp(operation, "DELETE") == 0) {
            scanf("%s", key);
            delete(root, key);
        }
        if (strcmp(operation, "PREFIX") == 0) {
            scanf("%s", key);
            int count = prefixCount(root, key);
            printf("%d ", count);
        }
        if (strcmp(operation, "END") == 0) {
            break;
        }
    }
    freeTrie(root);

    return 0;
}






