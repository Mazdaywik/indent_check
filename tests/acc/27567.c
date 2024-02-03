#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX_LEVEL 32
#define MAX_VALUE_LEN 10
#define SEED 31


typedef struct LinkedList_ {
    char *value;
    struct LinkedList_ *next;
} LinkedList;

LinkedList *pushFrontLinkedList(LinkedList *head, const char *value) {
    LinkedList *new_head = (LinkedList*)malloc(sizeof(LinkedList));
    new_head->next = head;
    new_head->value = (char*)malloc((strlen(value) + 1) * sizeof(char));
    strcpy(new_head->value, value);
    return new_head;
}

void deleteLinkedList(LinkedList *head) {
    LinkedList* deleted;
    while (head != NULL) {
        deleted = head;
        head = head->next;
        free(deleted->value);
        free(deleted);
    }
}


int generateLevel(int max_level) {
    int level;
    for (level = 1; level < max_level && !(rand() % 2); ++level) ;
    return level;
}

typedef struct Node Node;

typedef struct Pair {
    Node *next;
    int distance;
} Pair;

struct Node {
    int key;
    int level;
    LinkedList *values;
    Pair *ptrs_distance;
};

typedef struct SkipList {
    int max_level;
    Node *head;
} SkipList;

SkipList *buildSkipList(int max_level) {
    int i;
    SkipList *skip_list = (SkipList*)malloc(sizeof(SkipList));
    skip_list->head = (Node*)malloc(sizeof(Node));
    skip_list->max_level = max_level;
    skip_list->head->key = INT_MIN;
    skip_list->head->level = max_level;
    skip_list->head->values = NULL;
    skip_list->head->ptrs_distance = (Pair*)malloc(max_level * sizeof(Pair));
    for (i = 0; i < max_level; ++i) {
        skip_list->head->ptrs_distance[i].distance = 1;
        skip_list->head->ptrs_distance[i].next = NULL;
    }
    return skip_list;
}

void deleteSkipList(SkipList *list) {
    Node *head = list->head, * deleted;
    do {
        deleted = head;
        head = head->ptrs_distance[0].next;
        deleteLinkedList(deleted->values);
        free(deleted->ptrs_distance);
        free(deleted);
    } while (head != NULL);
    free(list);
}

char* lookupSkipList(SkipList *list, int key) {
    Node *head = list->head;
    int cur_level = list->max_level - 1;
    while (cur_level > 0 && head->key != key) {
        if (head->ptrs_distance[cur_level].next == NULL
          || head->ptrs_distance[cur_level].next->key > key) {
            --cur_level;
        } else {
            head = head->ptrs_distance[cur_level].next;
        }
    }
    if (!cur_level) {
        while (head->ptrs_distance[0].next != NULL
          && head->ptrs_distance[0].next->key <= key) {
            head = head->ptrs_distance[0].next;
        }
    }
    return head->key == key ? head->values->value : NULL;
}

int rankSkipList(SkipList *list, int key) {
    Node *head = list->head;
    int cur_level = list->max_level - 1;
    int rank = 0;
    while (cur_level > 0 && head->key != key) {
        if (head->ptrs_distance[cur_level].next == NULL
          || head->ptrs_distance[cur_level].next->key > key) {
            --cur_level;
        } else {
            rank += head->ptrs_distance[cur_level].distance;
            head = head->ptrs_distance[cur_level].next;
        }
    }
    if (!cur_level) {
        while (head->ptrs_distance[0].next != NULL
          && head->ptrs_distance[0].next->key <= key) {
            rank += head->ptrs_distance[0].distance;
            head = head->ptrs_distance[0].next;
        }
    }
    return rank;
}

void addSkipList(SkipList *list, int key, const char *value) {
    Pair **update_list = (Pair**)malloc(list->max_level * sizeof(Pair *));
    int *index_per_level = (int*)calloc(list->max_level, sizeof(int));
    LinkedList **value_list = NULL;

    for (int i = 0; i < list->max_level; ++i) {
        update_list[i] = &list->head->ptrs_distance[i];
    }

    int cur_key = list->head->key;
    int cur_level = list->max_level - 1;
    while (cur_level > 0 && cur_key != key) {
        if (update_list[cur_level]->next == NULL
          || update_list[cur_level]->next->key > key) {
            index_per_level[cur_level - 1] = index_per_level[cur_level];
            --cur_level;
        } else {
            cur_key = update_list[cur_level]->next->key;
            index_per_level[cur_level] += update_list[cur_level]->distance;
            value_list = &update_list[cur_level]->next->values;
            for (int i = 0; i <= cur_level; ++i) {
                update_list[i] = &update_list[cur_level]->next->ptrs_distance[i];
            }
        }
    }
    if (!cur_level) {
        index_per_level[0] = index_per_level[1];
        while (update_list[0]->next != NULL && update_list[0]->next->key <= key) {
            cur_key = update_list[cur_level]->next->key;
            value_list = &update_list[cur_level]->next->values;
            update_list[0] = &update_list[0]->next->ptrs_distance[0];
            ++index_per_level[0];
        }
    }

    if (cur_key == key) {
        *value_list = pushFrontLinkedList(*value_list, value);
        free(index_per_level);
        free(update_list);
        return;
    }

    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->key = key;
    int new_node_level = generateLevel(list->max_level);
    new_node->level = new_node_level;
    new_node->ptrs_distance = (Pair*)malloc(sizeof(Pair) * new_node_level);
    new_node->values = NULL;
    new_node->values = pushFrontLinkedList(new_node->values, value);

    for (int i = new_node_level; i < list->max_level; ++i) {
        ++update_list[i]->distance;
    }

    for (int i = 0; i < new_node_level; ++i) {
        new_node->ptrs_distance[i].next = update_list[i]->next;
        new_node->ptrs_distance[i].distance = (index_per_level[i] + update_list[i]->distance)
                                            - (index_per_level[0] + 1) + 1;
        update_list[i]->next = new_node;
        update_list[i]->distance = (index_per_level[0] + 1) - index_per_level[i];
    }

    free(index_per_level);
    free(update_list);
}


void removeByKeySkipList(SkipList *list, int key) {
    Pair** update_list = (Pair**)malloc(list->max_level * sizeof(Pair*));
    for (int i = 0; i < list->max_level; ++i) {
        update_list[i] = &list->head->ptrs_distance[i];
    }

    int cur_key = list->head->key;
    int cur_search_level = list->max_level - 1;
    while (cur_search_level > 0 && cur_key != key) {
        if (update_list[cur_search_level]->next == NULL
          || update_list[cur_search_level]->next->key >= key) {
            --cur_search_level;
        } else {
            cur_key = update_list[cur_search_level]->next->key;
            for (int i = 0; i <= cur_search_level; ++i) {
                update_list[i] = &update_list[cur_search_level]->next->ptrs_distance[i];
            }
        }
    }
    while (update_list[0]->next != NULL && update_list[0]->next->key < key) {
        update_list[0] = &update_list[0]->next->ptrs_distance[0];
    }

    Node *deleting_node = update_list[0]->next;
    for (int i = deleting_node->level; i < list->max_level; ++i) {
        --update_list[i]->distance;
    }

    for (int i = 0; i < deleting_node->level; ++i) {
        update_list[i]->next = deleting_node->ptrs_distance[i].next;
        update_list[i]->distance += deleting_node->ptrs_distance[i].distance - 1;
    }

    free(deleting_node->ptrs_distance);
    deleteLinkedList(deleting_node->values);
    free(deleting_node);
    free(update_list);
}

int main() {
    srand(SEED);
    char operation[MAX_VALUE_LEN], value[MAX_VALUE_LEN + 1];
    int key;

    SkipList *skip_list = buildSkipList(MAX_LEVEL);
    do {
        scanf("%s", operation);
        if (!strcmp(operation, "INSERT")) {
            scanf("%d%s", &key, value);
            addSkipList(skip_list, key, value);
        } else if (!strcmp(operation, "DELETE")) {
            scanf("%d", &key);
            removeByKeySkipList(skip_list, key);
        } else if (!strcmp(operation, "LOOKUP")) {
            scanf("%d", &key);
            printf("%s\n", lookupSkipList(skip_list, key));
        } else if (!strcmp(operation, "RANK")) {
            scanf("%d", &key);
            printf("%d\n", rankSkipList(skip_list, key) - 1);
        }
    } while (strcmp(operation, "END"));
    deleteSkipList(skip_list);

    return 0;
}
