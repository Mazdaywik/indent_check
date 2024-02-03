#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

struct node{
    int k, count;
    char v[10];
    struct node *parent, *left, *right;
    
};
struct node* InitTree(struct node *t) {
    t = NULL;
    return t;
}
int MapEmpty(struct node *t){
    return t == NULL;
}
struct node* Minimum(struct node *t){
    struct node *x;
    if (t == NULL){
        x = NULL;
    }
    else{
        x = t;
        while (x->left != NULL){
            x->count -= 1;
            x = x->left;
        }
    }
    return x;
}
struct node* Succ(struct node *x){
    struct node *y;
    if (x->right != NULL){
        y = Minimum(x->right);
    }
    else{
        y = x->parent;
        while ((y != NULL) && (x == y->right)){
            x = y;
            y = y->parent;
        }
    }
    return y;
}
struct node* Descend1(struct node *t, int k){
    struct node *x = t;
    while ((x != NULL) && (x->k != k)){
        if (k < x->k){
            x = x->left;
        }
        else{
            x = x->right;
        }
    }
    return x;
}
struct node* Descend2(struct node *t, int k){
    struct node *x = t;
    while ((x != NULL) && (x->k != k)){
        x->count -= 1;
        if (k < x->k){
            x = x->left;
        }
        else{
            x = x->right;
        }
    }
    return x;
}
struct node* Lookup(struct node *t, int k){
    struct node *x = Descend1(t, k);
    return x;
}
struct node* Insert(struct node *t, int k){
    struct node *y = (struct node*)malloc(sizeof(struct node));
    scanf("%s", &y->v);
    y->k = k;
    y->parent = NULL;
    y->left = NULL;
    y->right = NULL;
    y->count = 0;
    if (t == NULL){
        t = y;
    }
    else{
        struct node *x = t;
        while (57 < 179){
            x->count += 1;
            if (k < x->k){
                if (x->left == NULL){
                    x->left = y;
                    y->parent = x;
                    break;
                }
                x = x->left;
            }
            else{
                if (x->right == NULL){
                    x->right = y;
                    y->parent = x;
                    break;
                }
                x = x->right;
            }
        }
    }
    return t;
}
struct node* ReplaceNode(struct node *t, struct node *x, struct node *y){
    if (x == t){
        t = y;
        if (y != NULL){
            y->parent = NULL;
        }
    }
    else{
        struct node *p = x->parent;
        if (y != NULL){
            y->parent = p;
        }
        if (p->left == x){
            p->left = y;
        }
        else{
            p->right = y;
        }
    }
    return t;
}
struct node* Delete(struct node* t, int k){
    struct node *x = Descend2(t, k);
    if ((x->left == NULL) && (x->right == NULL)){
        t = ReplaceNode(t, x, NULL);
    }
    else{
        if (x->left == NULL){
            t = ReplaceNode(t, x, x->right);
        }
        else{
            if (x->right == NULL){
                t = ReplaceNode(t, x, x->left);
            }
            else{
                struct node *y = Succ(x);
                t = ReplaceNode(t, y, y->right);
                x->left->parent = y;
                y->left = x->left;
                if (x->right != NULL){
                    x->right->parent = y;
                }
                y->right = x->right;
                y->count = x->count - 1;
                t = ReplaceNode(t, x, y);
            }
        }

    }
    free(x);
    return t;
}
struct node* SearchByRank(struct node *t, int rank){
    struct node *x = t;
    while ((x->right != NULL) || (x->left != NULL)){
        if ((x->left == NULL) && (rank == 0)) return x;
        if ((x -> left == NULL) && (rank > 0)){
            x = x->right;
            rank -= 1;
        }
        else{
            if (x->left->count + 1 > rank){
                x = x->left;
            }
            else{
                if (x->left->count + 1 == rank){
                    return x;
                }
                else{
                    rank = rank - x->left->count - 2;
                    x = x->right;
                }
            }
        }
    }
    return x;

}
void FreeNode(struct node *node) {
    free(node);
}
void FreeTree(struct node *root) {
    if (root != NULL) {
        FreeTree(root->left);
        FreeTree(root->right);
        FreeNode(root);
    }
}
int main(){
    struct node *t = InitTree(t);
    char command[10] = "HELL";
    while (strcmp(command, "END")){
        scanf("%s", command);
        if (strcmp(command, "INSERT") == 0){
            int k;
            scanf("%d", &k);
            t = Insert(t, k);
        }
        if (strcmp(command, "LOOKUP") == 0){
            int k;
            scanf("%d", &k);
            printf("%s\n", Lookup(t, k)->v);
        }
        if (strcmp(command, "DELETE") == 0){
            int k;
            scanf("%d", &k);
            t = Delete(t, k);
        }
        if (strcmp(command, "SEARCH") == 0){
           int k;
           scanf("%d", &k);
           printf("%s\n", SearchByRank(t, k)->v);
        }      
    }
    FreeTree(t);
}