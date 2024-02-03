#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(char *a, char *b){
    return strcmp(a, b);
}

struct node{
    int v;
    char *k;
    int balance;
    struct node* parent;
    struct node* left;
    struct node* right;
} typedef node;

void* memdup(const void* mem, size_t size) { 
   void* out = malloc(size);

   if(out != NULL)
       memcpy(out, mem, size);

   return out;
}

node *create(char *key, int val) {
    node *new = malloc(sizeof(node));
    new->k = memdup(key, strlen(key)+1);
    new->left = NULL;
    new->right = NULL;
    new->balance = 0;
    new->v = val;
    new->parent = NULL;
    return new;
}

node *ReplaceNode(node *t, node *x, node *y){
    if(x == t){
        t = y;
        if(y != NULL){
            y->parent = NULL;
        }
    }else{
        node *p = x->parent;
        if(y != NULL){
            y->parent = p;
        }
        if(p->left == x){
            p->left = y;
        }else{
            p->right = y;
        }
    }
    return t;
}

node *RotateLeft(node *t, node *x) {
    node *y = x->right;
    if(y == NULL)
        return t;
    t = ReplaceNode(t, x, y);
    node *b = y->left;
    if (b != NULL)
        b->parent = x;
    x->right = b;
    x->parent = y;
    y->left = x;
    x->balance--;
    if (y->balance > 0)
        x->balance -= y->balance;
    y->balance--;
    if (x->balance < 0)
        y->balance += x->balance;
    return t;
}

node *RotateRight(node *t, node *x){
    node *y = x->left;
    if(y == NULL)
        return t;
    t = ReplaceNode(t, x, y);
    node *b = y->right;
    if(b != NULL)
        b->parent = x;
    x->left = b;
    x->parent = y;
    y->right = x;
    x->balance++;
    if (y->balance < 0)
        x->balance -= y->balance;
    y->balance++;
    if (x->balance > 0)
        y->balance += x->balance;
    return t;
}

node *InsertAVL( node *t , char *k , int v ){
    node *y = create(k, v);
    node *x;
    if(t == NULL){
        t = y;
    }else{
        x = t;
        while (1){
            if(compare(k, x->k) < 0){
                if(x->left == NULL){
                    x->left = y;
                    y->parent = x;
                    break;
                }
                x = x->left;
            }else{
                if(x->right == NULL){
                    x->right = y;
                    y->parent = x;
                    break;
                }
                x = x->right;
            }
        }
    }
    node *a = y;
    a->balance = 0;
    while (1){
        x = a->parent;
        if(x == NULL){
            break;
        }
        if(a == x->left){
            x->balance--;
            if(x->balance == 0)
                break;
            if(x->balance == -2) {
                if (a->balance == 1) {
                    t = RotateLeft(t, a);
                }
                t = RotateRight(t, x);
                break;
            }
        }else{
            x->balance++;
            if(x->balance == 0) break;
            if(x->balance == 2){
                if(a->balance == -1) {
                    t = RotateRight(t, a);
                }
                t = RotateLeft(t, x);
                break;
            }
        }
        a = x;
    }
    return t;
}

int find(node *t, char *k){
    node *x = t;
    while (x != NULL && compare(k, x->k) != 0){
        if(compare(k, x->k) < 0)
            x = x->left;
        else
            x = x->right;
    }
    if(x == NULL)
        return -1;
    return x->v;
}


void clear(struct node *root){
    if(root == NULL)
        return;
    clear(root->left);
    clear(root->right);
    free(root->k);
    free(root);
}

int main(int argc, char** argv) {
    char c;
    int countIdent = 0;
    node *root = NULL;
    int n;
    scanf("%d",&n);
    c = getc(stdin);
    c = getc(stdin);
    int spec[256] = {0};
    spec['-'] = 1;
    spec['*'] = 2;
    spec['/'] = 3;
    spec['('] = 4;
    spec[')'] = 5;
    char *s = calloc(n, sizeof(char));
    for(int i=0;i<n;){
        if(c == ' ') {
            if(i + 1 < n)
                c = getc(stdin);
            i++;
            continue;
        }
        if(c >= '0' && c <= '9'){
            int k = 0;
            s[k++] = c;
            if(i + 1 < n)
                c = getc(stdin);
            i++;
            while (c >= '0' && c <= '9' && i < n) {
                s[k++] = c;
                if(i + 1 < n)
                    c = getc(stdin);
                i++;
            }
            printf("CONST %s\n", s);
            memset(s, 0, k);
            continue;
        }
        if((c>='a'&&c<='z')||(c>='A'&&c<='Z')){
            int k = 0;
            while (((c >= '0' && c <= '9') || (c>='a'&&c<='z') || (c>='A'&&c<='Z')) && i < n) {
                s[k++] = c;
                if(i + 1 < n)
                    c = getc(stdin);
                i++;
            }
            int id = find(root, s);
            if(id == -1){
                printf("IDENT %d\n", countIdent);
                root = InsertAVL(root, s, countIdent++);
            }else{
                printf("IDENT %d\n", id);
            }
            memset(s, 0, k);
            continue;
        }
        printf("SPEC %d\n", spec[c]);
        if(i + 1 < n)
            c = getc(stdin);
        i++;
    }
    clear(root);
    free(s);
    return 0;
}
