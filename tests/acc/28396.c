#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Node {
    int key;
    int value;
    struct Node* next;
};
struct Node* makeNode(struct Node** hashtable, int index, int value, int m) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = index;
    newNode->value = value;
    newNode->next = hashtable[index % m];
    hashtable[index % m] = newNode;
    return newNode;
}
int At(struct Node** hashtable, int index, int m) {
    struct Node* current = hashtable[index % m];
    while (current != NULL) {
        if (current->key == index) {
            return current->value;
        }
        current = current->next;
    }
    return 0;
}
void Assign(struct Node** hashtable, int index, int value, int m) {
    int h = index % m;
    struct Node* current = hashtable[h];
    struct Node* prev = NULL;
    while (current != NULL) {
        if (current->key == index) {
            if (value != 0) {
                current->value = value;
            }
            else {
                if (prev == NULL) {
                    hashtable[h] = current->next;
                } 
                else {
                    prev->next = current->next;
                }
                free(current);
            }
            return;
        }
        prev = current;
        current = current->next;
    }
    if (value != 0) {
        makeNode(hashtable, index, value, m);
    }
}
void freehashtable(struct Node** hashtable, int m) {
    int i;
    for (i = 0; i < m; i++) {
        struct Node* current = hashtable[i];
        while (current != NULL) {
            struct Node* temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(hashtable);
}

int main() {
    int m;
    scanf("%d", &m);
    char req[10];
    int i, v;
    struct Node **hashtable = (struct Node**)malloc(sizeof(struct Node*) * m);
    for (i = 0; i < m; i++) {
        hashtable[i] = NULL;
    }
    scanf("%s", req);
    while (strcmp(req, "END") != 0) {
        if (strcmp(req, "ASSIGN") == 0) {
            scanf("%d %d", &i, &v);
            Assign(hashtable, i, v, m);
        } 
        else if (strcmp(req, "AT") == 0) {
            scanf("%d", &i);
            printf("%d\n", At(hashtable, i, m));
        }
        scanf("%s", req);
    }
    freehashtable(hashtable, m);
    return 0;
}