#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int key, value;
    struct Node *parent, *left, *right;
};

struct Tree
{
    struct Node *root;
};

struct Node *Descend(struct Tree *tree, int key)
{
    struct Node *x = tree->root;
    while (x != NULL && x->key != key)
    {
        if (key < x->key)
        {
            x = x->left;
        }
        else
        {
            x = x->right;
        }
    }
    return x;
}

struct Node *Insert(struct Tree *tree, int key, int value)
{
    struct Node *y = (struct Node *)malloc(sizeof(struct Node));
    y->key = key, y->value = value, y->parent = NULL, y->left = NULL, y->right = NULL;
    if (!tree->root)
    {
        tree->root = y;
    }
    else
    {
        struct Node *x = tree->root;
        for (;;)
        {
            if (key < x->key)
            {
                if (x->left == NULL)
                {
                    x->left = y, y->parent = x;
                    break;
                }
                x = x->left;
            }
            else
            {
                if (x->right == NULL)
                {
                    x->right = y, y->parent = x;
                    break;
                }
                x = x->right;
            }
        }
    }
    return y;
}

void clear(struct Node *node)
{
    if (node->left)
    {
        clear(node->left);
    }
    if (node->right)
    {
        clear(node->right);
    }
    free(node);
}

int main()
{
    int n;
    scanf("%d", &n);
    struct Tree tree;
    tree.root = NULL;
    int xor = 0;
    long long ans=0;
    for (int i = 0; i < n; ++i)
    {
        int k;
        scanf("%d", &k);
        xor ^= k;
        struct Node *newNode = Descend(&tree, xor);
        if (!newNode)
        {
            newNode = Insert(&tree, xor, 0);
        }
        newNode->value++;
        if (xor == 0)
        {
            ans += newNode->value;
        }
        else
        {
            ans += newNode->value - 1;
        }
        
    }
    printf("%lld", ans);
    if (tree.root)
    {
        clear(tree.root);
    }
    return 0;
}