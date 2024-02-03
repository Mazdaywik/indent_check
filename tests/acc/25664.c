#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TrieNode {
    struct TrieNode* children[26];
    int isEndOfWord;
} TrieNode;

TrieNode* createNode() {
    TrieNode* node = malloc(sizeof(TrieNode));
    node->isEndOfWord = 0;
    for (int i = 0; i < 26; i++) {
        node->children[i] = NULL;
    }
    return node;
}

void insert(TrieNode* root, char* key) {
    TrieNode* curr = root;
    int len = strlen(key);
    for (int i = 0; i < len; i++) {
        int index = key[i] - 'a';
        if (curr->children[index] == NULL) {
            curr->children[index] = createNode();
        }
        curr = curr->children[index];
    }
    curr->isEndOfWord = 1;
}

int search(TrieNode* root, char* key) {
    TrieNode* curr = root;
    int len = strlen(key);
    for (int i = 0; i < len; i++) {
        int index = key[i] - 'a';
        if (curr->children[index] == NULL) {
            return 0;
        }
        curr = curr->children[index];
    }
    return curr != NULL && curr->isEndOfWord;
}

void delete(TrieNode* root, char* key) {
    TrieNode* curr = root;
    int len = strlen(key);
    for (int i = 0; i < len; i++) {
        int index = key[i] - 'a';
        if (curr->children[index] == NULL) {
            return;
        }
        curr = curr->children[index];
    }
    curr->isEndOfWord = 0;
}

int countWords(TrieNode* node) {
    int count = 0;
    if (node->isEndOfWord) {
        count++;
    }
    for (int i = 0; i < 26; i++) {
        if (node->children[i] != NULL) {
            count += countWords(node->children[i]);
        }
    }
    return count;
}

int countPrefix(TrieNode* root, char* prefix) {
    TrieNode* curr = root;
    int len = strlen(prefix);
    for (int i = 0; i < len; i++) {
        int index = prefix[i] - 'a';
        if (curr->children[index] == NULL) {
            return 0;
        }
        curr = curr->children[index];
    }
    return countWords(curr);
}

void destroyTrie(TrieNode* root) {
    if (root == NULL) {
        return;
    }
    for (int i = 0; i < 26; i++) {
        destroyTrie(root->children[i]);
    }
    free(root);
}

int main() {
    TrieNode* root = createNode();

    char operation[100];
    while (scanf("%s", operation) != EOF) {
        if (strcmp(operation, "INSERT") == 0) {
            char key[100000];
            scanf("%s", key);
            insert(root, key);
        }
        else if (strcmp(operation, "DELETE") == 0) {
            char key[100000];
            scanf("%s", key);
            delete(root, key);
        }
        else if (strcmp(operation, "PREFIX") == 0) {
            char prefix[100000];
            scanf("%s", prefix);
            int count = countPrefix(root, prefix);
            printf("%d\n", count);
        }
        else if (strcmp(operation, "END") == 0) {
            break;
        }
    }
    destroyTrie(root);
    return 0;
}
