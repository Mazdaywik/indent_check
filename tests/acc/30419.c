#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tree{
    struct tree *left, *right, *parent;
    int ind, val;
}typedef tree;

tree *create_new(tree *parent, int value, int index) {
    tree *new = malloc(sizeof(tree));
    new->parent = parent;
    new->left = new->right = NULL;
    new->val = value;
    new->ind = index;
    return new;
}


void add(tree* now_root, int index, int value){
    if(now_root->ind == index){
        if(value == 0){
            tree *left = now_root->left;
            tree *right = now_root->right;
            int isParentLeft = now_root->parent->left != NULL && now_root->parent->left->ind == index;
            if(left == NULL){
                if(isParentLeft)
                    now_root->parent->left = right;
                else
                    now_root->parent->right = right;
                if(right!=NULL)
                    right->parent = now_root->parent;
                free(now_root);
                return;
            }
            if(right == NULL){
                if(isParentLeft)
                    now_root->parent->left = left;
                else
                    now_root->parent->right = left;
                if(left!=NULL)
                    left->parent = now_root->parent;
                free(now_root);
                return;
            }
            tree *now = now_root->parent;
            if(isParentLeft){
                now->left = left;
                left->parent = now;
                now = left;
            }else{
                now->right = left;
                left->parent = now;
                now = left;
            }
            free(now_root);
            while (1){
                if(now->ind > right->ind) {
                    if (now->left == NULL) {
                        now->left = right;
                        right->parent = now;
                        return;
                    }
                    now = now->left;
                }
                if(now->ind < right->ind) {
                    if (now->right == NULL) {
                        now->right = right;
                        right->parent = now;
                        return;
                    }
                    now = now->right;
                }
            }
        }
        now_root->val = value;
        return;
    }
    if(index<now_root->ind){
        if(now_root->left == NULL){
            now_root->left = create_new(now_root, value, index);
            return;
        }
        add(now_root->left, index, value);
    }
    if(index>now_root->ind){
        if(now_root->right == NULL){
            now_root->right = create_new(now_root, value, index);
            return;
        }
        add(now_root->right, index, value);
    }
}

int at(tree* now_root, int index){
    if(now_root->ind == index){
        return now_root->val;
    }
    if(index<now_root->ind){
        if(now_root->left == NULL){
            return 0;
        }
        return at(now_root->left, index);
    }
    if(index>now_root->ind){
        if(now_root->right == NULL){
            return 0;
        }
        return at(now_root->right, index);
    }
}

void run(tree** disp, int m) {
    char operation[10];
    int value, index;
    do {
        scanf("%s", operation);
        if (strcmp(operation, "ASSIGN") == 0) {
            scanf("%d%d", &index, &value);
            add(disp[index%m], index, value);
        } else if (strcmp(operation, "AT") == 0) {
            scanf("%d", &index);
            printf("%d\n", at(disp[index%m], index));
        }
    } while (strcmp(operation, "END"));
}

tree *create_root() {
    tree *new = malloc(sizeof(tree));
    new->parent = new->left = new->right = NULL;
    new->val = -1;
    new->ind = -1;
    return new;
}

void clear_tree(tree *now){
    if(now == NULL)
        return;
    clear_tree(now->left);
    clear_tree(now->right);
    free(now);
}

void clear(tree **disp, int m){
    for(int i = 0 ; i < m; i++){
        clear_tree(disp[i]);
    }
    free(disp);
}

int main(){
    int m;
    scanf("%d", &m);
    tree **disp = malloc(m * sizeof(tree*));
    for(int i = 0; i < m; i++)
        disp[i] = create_root();
    run(disp, m);
    clear(disp, m);
}