#include <stdio.h>
#include <math.h>
#include <stdlib.h>

long gcd(long a, long b)
{
    if (a < 0)
        a = -a;
    if (b < 0)
        b = -b;

    if(a == 0)
        return b;
    if(b == 0)
        return a;

   return gcd(b, a % b);
}

void build_tree(long *arr, long *tree, long v, long left, long right)
{
    if (left == right)
        tree[v] = arr[left];
    else
    {
        long middle = (left + right) / 2;
        build_tree(arr, tree, v * 2, left, middle);
        build_tree(arr, tree, v * 2 + 1, middle + 1, right);
        tree[v] = gcd(tree[v * 2], tree[v * 2 + 1]);
    }
}

long gcd_tree(long *tree, long v, long tree_left, long tree_right, long left, long right)
{
    if (left > right)
        return 0;
    if (left == tree_left && right == tree_right)
        return tree[v];

    long middle = (tree_left + tree_right) / 2;

    long a = gcd_tree(tree, v * 2, tree_left, middle, left, fmin(right, middle));
    long b = gcd_tree(tree, v * 2 + 1, middle + 1, tree_right, fmax(left, middle + 1), right);

    return gcd(a, b);
}

int main()
{
    int n;
    scanf("%d", &n);

    long arr[n];
    for (int i = 0; i < n; i++)
        scanf("%ld", &arr[i]);

    long *tree = (long *)malloc(4 * n * sizeof(long));
    build_tree(arr, tree, 1, 0, n - 1);

    int m;
    scanf("%d", &m);

    long ans[m];
    for (int i = 0; i < m; i++)
    {
        long left, right;
        scanf("%ld %ld", &left, &right);
        long res = gcd_tree(tree, 1, 0, n - 1, left, right);
        ans[i] = res;
    }

    for(int i = 0; i < m; i++)
        printf("%ld\n", ans[i]);
    
    free(tree);

    return 0;
}