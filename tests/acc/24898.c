#include <stdio.h>
#include <stdlib.h>

struct Elem {
    long long key;
    char *val;
    int count;
    struct Elem *left;
    struct Elem *right;
};

struct Elem *INSERT(struct Elem *start, struct Elem *new){
    if(new == NULL)
        return start;
    if(start == NULL) {
        return new;
    }
    start->count += new->count;
    if(start->key > new->key){
        start->left = INSERT(start->left, new);
    }else{
        start->right = INSERT(start->right, new);
    }
    return start;
}
struct Elem *DELETE(struct Elem *start, long long key){
    if(key == start->key){
        struct Elem *was = start;
        start = INSERT(start->right, start->left);
        free(was->val);
        free(was);
        return start;
    }
    start->count--;
    if(key < start->key) {
        start->left = DELETE(start->left, key);
        return start;
    } else{
        start->right = DELETE(start->right, key);
        return start;
    }
}
struct Elem *LOOKUP(struct Elem *start, long long key){
    if(start->key == key)
        return start;
    if(key < start->key)
        return LOOKUP(start->left, key);
    return LOOKUP(start->right, key);
}

char * SEARCH(struct Elem *start, int x){
    if((start->left != NULL ? start->left->count : 0) + 1 == x)
        return start->val;
    if(start->left != NULL){
        if(start->left->count >= x)
            return SEARCH(start->left, x);
        if(start->left->count < x)
            return SEARCH(start->right, x - start->left->count - 1);
    }else{
        if(start->right == NULL)
            return start->val;
        return SEARCH(start->right, x - 1);
    }
}


void clear(struct Elem *start){
    if(start == NULL)
        return;
    struct Elem *left = start->left;
    struct Elem *right = start->right;
    free(start->val);
    free(start);
    clear(left);
    clear(right);
}

int main(int argc, char** argv) {
    struct Elem *start = NULL;
    char command[10];
    long long key;
    scanf("%s", command);
    while (command[0] != 'E'){
        if(command[0] == 'I'){
            char * val = malloc(100 * sizeof(char));
            scanf("%lld%s", &key, val);
            struct Elem *new = malloc(sizeof(struct Elem));
            new->val = val;
            new->key = key;
            new->left = NULL;
            new->right = NULL;
            new->count = 1;
            start = INSERT(start, new);
        }
        if(command[0] == 'D'){
            scanf("%lld", &key);
            start = DELETE(start, key);
        }
        if(command[0] == 'L'){
            scanf("%lld", &key);
            struct Elem *now = LOOKUP(start, key);
            printf("%s\n", now->val);
        }
        if(command[0] == 'S'){
            int x;
            scanf("%d", &x);
            printf("%s\n", SEARCH(start, x + 1));
        }
        scanf("%s", command);
    }
    clear(start);
    return 0;
}
