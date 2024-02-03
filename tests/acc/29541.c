#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>


struct Pair {
    int64_t key;
    char value[16];
};

struct Node
{
    struct Node *left;
    struct Node *right;
    struct Pair pair;
    int count;
};

struct Node* create_node(int key, char const *v){
    struct Node* e = calloc(1, sizeof(struct Node));
    e->pair.key = key;
    e->count = 0;
    strcpy(e->pair.value, v);
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
void insert(struct Node **root, int key, char const *v)
{
    if (!*root) {
        *root = create_node(key, v);
        return;
    }
    struct Node *it = *root;
    while (it) {
        it->count++;
        if (it->pair.key > key) {
            if (it->left) {
                it = it->left;
            }
            else {
                it->left = create_node(key, v);
                break;
            }
        }
        else {
            if (it->right) {
                it = it->right;
            }
            else {
                it->right = create_node(key, v);
                break;
            }
        }
    }
}
struct Node* lookup(struct Node *it, int key) {
    while (it->pair.key != key) {
        it = it->pair.key > key ? it->left : it->right;
    }
    return it;
}
void delete(struct Node **root, int key)
{
    struct Node *parent = NULL;
    struct Node *it = *root;
    while (it->pair.key != key) {
        it->count--;
        parent = it;
        it = it->pair.key > key ? it->left : it->right;
    }

    //it->count -= 1;
    if (it->left != NULL && it->right != NULL) {
        parent = it;
        struct Node *save = it->right;
        while (save->left) {
            save->count--;
            parent = save;
            save = save->left;
        }

        it->pair.key = save->pair.key;
        strcpy(it->pair.value, save->pair.value);

        it->count--;
        it = save;
    }


    struct Node *child = it->left ? it->left : it->right;

    if (parent == NULL) {
        *root = child;
    }
    else if (parent->left == it) {
        parent->left = child;
    }
    else {
        parent->right = child;
    }

    destroy_node(it);
}
struct Node* search(struct Node *root, int rel)
{
    do {
        if (root->left) {
            if (root->left->count == rel - 1)
                break;

            if (root->left->count > rel - 1)
                root = root->left;
            else {
                rel -= root->left->count + 2;
                root = root->right;
            }
        }
        else {
            if (!rel)
                break;
            rel--;
            root = root->right;
        }
    } while (root);
    return root;
}
void print_tree(struct Node *root, int width)
{
    if (!root) return;
    print_tree(root->right, width + 1);
    for (int i = 0; i < width; i++)
        printf(" ");
    printf("%lld [%i]\n", root->pair.key, root->count);
    print_tree(root->left, width + 1);

}

int main()
{
    //freopen("ranktree/input.txt", "r", stdin);
    //freopen("ranktree/output.txt", "w", stdout);
    struct Node *root = NULL;
    int c = 0;
    for (;;) {
        char command[10];
        scanf("%s", command);
        c++;
        if (!strcmp(command, "END")) {
            break;
        }
        int x1;
        scanf("%i", &x1);
        if (!strcmp(command, "INSERT")) {
            char x2[16];
            scanf("%s", x2);
            insert(&root, x1, x2);
        }
        else if (!strcmp(command, "DELETE")) {
            //print_tree(root, 0);
            delete(&root, x1);
            //printf("============================\n");
            //print_tree(root, 0);
        }
        else if (!strcmp(command, "SEARCH")) {
            struct Node* res = search(root, x1);
            printf("%s\n", res->pair.value);
        }
        else if (!strcmp(command, "LOOKUP")) {
            struct Node * res = lookup(root, x1);
            printf("%s\n", res->pair.value);
        }
    }
    destroy_tree(root);
}