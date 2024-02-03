#include <stdio.h>
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <wchar.h>

#define min(a,b) ((a) < (b) ? (a) : (b))
//#define max(a, b) ((a) < (b) ? (b) : (a))
#define maxsz (int)1e6 + 1000
#define inf (int)1e9

typedef long long ll;

int maxx(int x, int y) {
    return x < y ? y : x;
}

struct Node {
    struct Node *prev;
    struct Node *l;
    struct Node *r;
    ll key, val;
};

struct Tree {
    struct Node *root;
};

struct Node *search(struct Tree *t, ll key){
    struct Node *cur = t->root;
    while (cur && cur->key != key){
        if (cur->key > key){
            cur = cur->l;
        }
        else{
            cur = cur->r;
        }
    }
    return cur;
}

struct Node* insert(struct Tree* t, ll key, ll val){
    struct Node* cur = (struct Node*) malloc(sizeof (struct Node));
    cur->prev = NULL;
    cur->l = NULL;
    cur->r = NULL;
    cur->key = key;
    cur->val = val;
    if (!t->root){
        t->root = cur;
        return t->root;
    }
    struct Node* tmp = t->root;
    while (1){
        if (key < tmp->key){
            if (!tmp->l){
                cur->prev = tmp;
                tmp->l = cur;
                break;
            }
            tmp = tmp->l;
        }
        else{
            if (!tmp->r){
                cur->prev = tmp;
                tmp->r = cur;
                break;
            }
            tmp = tmp->r;
        }
    }
    return cur;
}

void freee(struct Node *e) {
    if (e == 0)
        return;
    freee(e->l);
    freee(e->r);
    free(e);
}

int main(){
    int n;
    ll cnt = 0, su = 0;
    char com[20];
    scanf("%d", &n);
    struct Tree t;
    t.root = NULL;
    for (int i = 0; i < n; ++i){
        ll x;
        scanf("%lld", &x);
        su ^= x;
        struct Node *cur = search(&t, su);
        if (!cur){
            cur = insert(&t, su, 0);
        }
        cur->val += 1;
        if (!su){
            cnt += cur->val;
        }
        else{
            cnt += cur->val - 1;
        }
    }
    if (t.root){
        freee(t.root);
    }
    printf("%lld", cnt);
    return 0;
}