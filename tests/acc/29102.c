#include <stdio.h>
#include <stdlib.h>

struct stack{
    long val, ind;
    struct stack *prev;
};

struct stack *newStack(long i, long val, struct stack *prev){
    struct stack *root = prev;
    while (root!=NULL && root->ind != i)
        root = root->prev;
    if (root == NULL) {
        if (val != 0) {
            struct stack *new = malloc(sizeof(struct stack));
            new->prev = prev;
            new->val = val;
            new->ind = i;
            return new;
        }
        return prev;
    }
    if(val == 0){
        if(root == prev){
            struct stack *ret = prev->prev;
            free(prev);
            return ret;
        }
        root = prev;
        while (root!=NULL && root->prev->ind != i)
            root = root->prev;
        struct stack *free_node = root->prev;
        if(free_node->prev == NULL){
            free(free_node);
            root->prev = NULL;
            return prev;
        }
        root->prev = free_node->prev;
        free(free_node);
        return prev;
    }
    root->val = val;
    return prev;
}

int compare(char *a, char *b){
    return (a[0] == b[0]) && (a[1] == b[1]);
}

int main() {
    char *instruction = calloc(8, sizeof(char));
    long i, x, m;
    scanf("%ld", &m);
    struct stack **table = calloc(m, sizeof(struct stack));
    scanf("%s", instruction);
    while (!compare(instruction, "END")) {
        if (compare(instruction, "ASSIGN")) {
            scanf("%ld%ld", &i, &x);
            table[i%m] = newStack(i, x, table[i%m]);
            scanf("%s", instruction);
            continue;
        }
        if (compare(instruction, "AT")) {
            scanf("%ld", &i);
            struct stack *root = table[i%m];
            while (root!=NULL && root->ind != i)
                root = root->prev;
            printf("%ld\n", root==NULL ? 0 : root->val);
            scanf("%s", instruction);
            continue;
        }
    }
    for(i = 0 ; i < m ; i++){
        struct stack *s = table[i];
        while (s != NULL){
            struct stack *prev;
            prev = s->prev;
            free(s);
            s = prev;
        }
    }
    free(table);
    free(instruction);
    return 0;
}