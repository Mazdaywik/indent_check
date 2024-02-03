#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

struct Pair {
    int64_t key;
    int value;
};

struct Node
{
    struct Node *left;
    struct Node *right;
    struct Pair pair;
};

struct Node* create_node(struct Pair pair){
    struct Node* e = calloc(1, sizeof(struct Node));
    e->pair = pair;
    return e;
}
void destroy_node(struct Node *e)
{
    free(e);
}
void destroy_tree(struct Node *e) {
    if (!e) {
        return;
    }
    destroy_tree(e->left);
    destroy_tree(e->right);
    destroy_node(e);
}
struct Node* insert(struct Node **root, struct Pair data)
{
    if (!*root) {
        return (*root = create_node(data));
    }
    struct Node *it = *root;
    while (it) {
        if (it->pair.key == data.key) {
            return it;
        }
        if (it->pair.key > data.key) {
            if (it->left)
                it = it->left;
            else {
                return (it->left = create_node(data));
            }
        }
        else {
            if (it->right)
                it = it->right;
            else {
                return (it->right = create_node(data));
            }
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    struct Node *root = NULL;
    int64_t sum = 0, res = 0;
    while (n--) {
        int64_t x;
        scanf("%ld", &x);
        sum ^= x;

        struct Node *e = insert(&root, (struct Pair){sum, 0});
        e->pair.value++;
        res += (sum == 0) ? e->pair.value : (e->pair.value - 1);
    }
    printf("%ld", res);
    destroy_tree(root);
}