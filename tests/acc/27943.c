#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct Elem{
        int k;
        char* v;
        int count;
        struct Elem* parent;
        struct Elem* left;
        struct Elem* right;
};

struct Elem* InitBinarySearchTree(){
        struct Elem* t = NULL;
        return t;
}

struct Elem* Minimum(struct Elem* t){
        if(t == NULL){
                return NULL;
        }
        else{
                struct Elem* x = t;
                while(x->left != NULL){
                        x = x->left;
                }
                return x;
        }
}

struct Elem* Succ(struct Elem* x){
        if(x->right != NULL){
                return Minimum(x->right);
        }
        else{
                struct Elem* y = x->parent;
                while((y != NULL) && (y->right != x)){
                        x = y;
                        y = y->parent;
                }
                return y;
        }
}

struct Elem* Insert(struct Elem* t, int k, char* v){
        struct Elem* y = malloc(sizeof(struct Elem));
        y->k = k;
        y->v = v;
        y->count = 1;
        y->parent = NULL;
        y->left = NULL;
        y->right = NULL;
        if(t == NULL){
                t = y;
        }
        else{
                struct Elem* x = t;
                while(1 == 1){
                        if(x->k == k){
                                printf("AAAAAAAAAA BOBER KURVA");
                        }
                        if(k < x->k){
                                if(x->left == NULL){
                                        x->count++;
                                        x->left = y;
                                        y->parent = x;
                                        break;
                                }
                                x->count ++;
                                x = x->left;
                        }
                        else{
                                if(x->right == NULL){
                                        x->count++;
                                        x->right = y;
                                        y->parent = x;
                                        break;
                                }
                                x->count++;
                                x = x->right;
                        }
                }
        }
        return t;
}


struct Elem* Descend(struct Elem* t, int k){
        struct Elem* x = t;
        while((x != NULL) && (x->k != k)){
                if(k < x->k) x = x->left;
                else x = x->right;
        }
        return x;
}

char* Lookup(struct Elem* t, int k){
        struct Elem* x = Descend(t, k);
        if(x == NULL){
                printf("AAAAAAAAAAA JAPONSKY GORODOVOI");
        }
        return x->v;
}


char* SearchByRank(struct Elem* t, int rank){
        rank++;
        struct Elem* x = t;
        int add = 0;
        while(x != NULL){
                if(x->right){
                        if((x->count - x->right->count + add < rank)){
                                add += x->count - x->right->count;
                                x = x->right;
                        }
                        else if((x->count - x->right->count + add > rank)){
                                x = x->left;
                        }
                        else break;
                }
                else if(x->count + add == rank) break;
                else x = x->left;
        }
        return x->v;
}


struct Elem* ReplaceNode(struct Elem* t, struct Elem* x, struct Elem* y){
//      printf("%s  %s", x->v, y->v);
        if(x == t){
//              printf("a\n");
                t = y;
                if(y != NULL){
                        y->parent = NULL;
                }
        }
        else{
                struct Elem* p = x->parent;
                if(y != NULL){
                        y->parent = p;
                }
                if(p->left == x){
                        p->left = y;
                }
                else{
                        p->right = y;
                }
        }
        return t;
}

struct Elem* DescendDel(struct Elem* t, int k){
        struct Elem* x = t;
        while((x != NULL) && (x->k != k)){
                x->count--;
                if(k < x->k) x = x->left;
                else x = x->right;
        }
        return x;
}

struct Elem* MinimumDel(struct Elem* t){
        struct Elem* x = t;
        while(x->left != NULL){
                x->count--;
                x = x->left;
        }
        return x;
}

struct Elem* SuccDel(struct Elem* x){
        return MinimumDel(x->right);
}


struct Elem* Delete(struct Elem* t, int k){
        struct Elem* x = DescendDel(t, k);
        if(x == NULL){
                printf("AAAAAAAAAAAA BLYAXA MUXA");
        }
        if((x->left == NULL) && (x->right == NULL)){
//              printf("1\n");
                t = ReplaceNode(t, x, NULL);
        }
        else if(x->left == NULL){
//              printf("2\n");
                t = ReplaceNode(t, x, x->right);
//              printf("%s\n", t->v);
        }
        else if(x->right == NULL){
//              printf("3\n");
                t = ReplaceNode(t, x, x->left);
        }
        else{
                struct Elem* y = SuccDel(x);
                y->count = x->count - 1;
                t = ReplaceNode(t, y, y->right);
                x->left->parent = y;
                y->left = x->left;
                if(x->right != NULL){
                        x->right->parent = y;
                }
                y->right = x->right;
                t = ReplaceNode(t, x, y);
        }
        free(x->v);
        free(x);
        return t;
}

void Free(struct Elem* t){
        if(t != NULL){
                if(t->left != NULL) Free(t->left);
                if(t->right != NULL) Free(t->right);
                free(t->v);
                free(t);
        }
}

int main(){
        struct Elem* t = InitBinarySearchTree();
        char input[10000] = "a";
        int k;
        while(strcmp(input, "END") != 0){
                scanf("%s", input);
                if(strcmp(input, "INSERT") == 0){
                        char* v = malloc(11);
                        scanf("%d%s", &k, v);
                        t = Insert(t, k, v);
                }
                if(strcmp(input, "LOOKUP") == 0){
                        scanf("%d", &k);
                        printf("%s\n", Lookup(t, k));
                }
                if(strcmp(input, "SEARCH") == 0){
                        scanf("%d", &k);
                        printf("%s\n", SearchByRank(t, k));
                }
                if(strcmp(input, "DELETE") == 0){
                        scanf("%d", &k);
                        t = Delete(t, k);
                }
        }
        Free(t);
        return 0;
}