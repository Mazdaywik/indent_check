#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node Node;


struct Node
{
    long long int key, val;
    Node *parent, *left, *right;
};

typedef struct Tree
{
    Node *root;
} Tree;

Node* tree_find_node(Tree *tree, long long int key)
{
    Node *node  = (*tree).root;
    while(node && (*node).key != key) {
        if(key < (*node).key) node = (*node).left;
        else node = (*node).right;
    }
    return node;
}

Node* tree_insert_node(Tree *tree, long long int key, long long int val)
{
    Node *new;
    new = (Node*)malloc(sizeof(Node));
    (*new).key = key;
    (*new).val = val;
    (*new).parent = NULL;
    (*new).left = NULL;
    (*new).right = NULL;
    if(!(*tree).root) {
        (*tree).root = new;
        return (*tree).root;
    }

    Node* node = (*tree).root;
    while(1 == 1) {
        if(key < (*node).key)
        {
            if(!(*node).left)
            {
                (*node).left = new;
                (*new).parent = node;
                break;
            }
            node = (*node).left;
        }
        else
        {
            if(!(*node).right)
            {
                (*node).right = new;
                (*new).parent = node;
                break;
            }
            node = (*node).right;
        }
    }

    return new;
}

void tree_clear_node(Node *node)
{
    if((*node).left) tree_clear_node((*node).left);
    if((*node).right) tree_clear_node((*node).right);
    free(node);
}



int main()
{
    long long int n;
    scanf("%lld", &n);
    Tree tree;
    tree.root = NULL;
    long long int cnt = 0, sum = 0;
    for(int i = 0; i < n; i++)
    {
        long long int x;
        scanf("%lld", &x);
        sum ^= x;
        Node* node = tree_find_node(&tree, sum);
        if(!node) 
            node = tree_insert_node(&tree, sum, 0);
        (*node).val++;
        if(sum == 0) 
            cnt += (*node).val;
        else 
            cnt += (*node).val - 1;
    }
    printf("%lld", cnt);
    if(tree.root)
        tree_clear_node(tree.root);
    return 0;
}
