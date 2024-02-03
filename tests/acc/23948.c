#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

void build_tree(long *arr, long *tree, long v, long left, long right)
{
    if (left == right)
        tree[v] = arr[left];
    else
    {
        long middle = (left + right) / 2;
        build_tree(arr, tree, v * 2, left, middle);
        build_tree(arr, tree, v * 2 + 1, middle + 1, right);
        tree[v] = fmax(tree[v * 2], tree[v * 2 + 1]);
    }
}

long max_tree(long *tree, long v, long tree_left, long tree_right, long left, long right)
{
    if (left > right)
        return -1000000001;
    if (left == tree_left && right == tree_right)
        return tree[v];

    long middle = (tree_left + tree_right) / 2;

    return fmax(max_tree(tree, v * 2, tree_left, middle, left, fmin(right, middle)), max_tree(tree, v * 2 + 1, middle + 1, tree_right, fmax(left, middle + 1), right));
}

void update_tree(long *tree, long v, long left, long right, int pos, int new_val)
{
    if (left == right)
        tree[v] = new_val;
    else
    {
        long middle = (left + right) / 2;
        if (pos <= middle)
            update_tree(tree, v * 2, left, middle, pos, new_val);
        else
            update_tree(tree, v * 2 + 1, middle + 1, right, pos, new_val);
        tree[v] = fmax(tree[v * 2], tree[v * 2 + 1]);
    }
}

int main()
{
    long n;
    scanf("%ld", &n);

    long arr[n];
    for (long i = 0; i < n; i++)
        scanf("%ld", &arr[i]);

    long *tree = (long *)malloc(4 * n * sizeof(long));
    build_tree(arr, tree, 1, 0, n - 1);

    char command[4];
    long arg_1, arg_2;
    scanf("%s %ld %ld", command, &arg_1, &arg_2);


    while (strcmp(command, "END") != 0)
    {
        if (strcmp(command, "MAX") == 0)
        {
            long res = max_tree(tree, 1, 0, n - 1, arg_1, arg_2);
            printf("%ld\n", res);
        }
        else if (strcmp(command, "UPD") == 0)
        {
            update_tree(tree, 1, 0, n - 1, arg_1, arg_2);
        }

        scanf("%s", command);
        if(strcmp(command, "END") != 0)
            scanf("%ld %ld", &arg_1, &arg_2);
    }

    free(tree);
    return 0;
}