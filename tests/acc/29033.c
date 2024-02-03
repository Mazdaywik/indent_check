#include <stdio.h>
#include <stdlib.h>

typedef struct List{
    int key;
    int value;
    struct List* next;
} List;

List* initList(int key, int value) {
    List* new_node = (List*) malloc(sizeof(List));
    new_node->key = key;
    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}

int isListEmpty(List* head) {
    return (head == NULL);
}

List* listSearch(List* head, int key) {
    List* temp = head;
    while (temp != NULL && temp->key != key) {
        temp = temp->next;
    }
    return temp;
}

void insertBeforeStart(List** head, int key, int value) {
    List* new_node = initList(key, value);
    new_node->next = *head;
    *head = new_node;
}

void initHash(int n, List** hash_table) {
    int i;
    for (i = 0; i < n; i++) {
        hash_table[i] = initList(0, 0);
    }
}

List* searchHash(List** hash_table, int key, int n) {
    List* result;
    int index = abs(key) % n;
    result = listSearch(hash_table[index], key);
    return result;
}

int main() {
    int m, first_digit, second_digit;
    char cmd[7];

    scanf("%d", &m);

    List* hash_table[m];
    initHash(m, hash_table);

    while(1) {
        scanf("%s", cmd);

        if (cmd[1] == 'T') {
            scanf("%d", &first_digit);
            List* result = searchHash(hash_table, first_digit, m);
            if (result == NULL) {
                printf("0\n");
            } else {
                printf("%d\n", result->value);
            }
        } else if (cmd[1] == 'S') {
            scanf("%d %d", &first_digit, &second_digit);
            List* result = searchHash(hash_table, first_digit, m);
            if (result != NULL) {
                result->value = second_digit;
            } else {
                insertBeforeStart(&hash_table[abs(first_digit) % m], first_digit, second_digit);
            }
        } else break;
    }

    for (int i = 0; i < m; i++) {
        List* current = hash_table[i];
        List* next;
        while (current != NULL) {
            next = current->next;
            free(current);
            current = next;
        }
    }

    return 0;
}
