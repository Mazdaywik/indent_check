#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int n = 0;
int *arr= NULL;
int *tree = NULL;

#define MIN(a, b) (a < b ? a : b)
#define MAX(a, b) (a > b ? a : b)
int max(i, a, b, l, r)
        int l, r, i, a, b;
{
    if (l > r)
        return INT_MIN;
    if(l == a && r == b)
        return tree[i];

    int m = a + (b - a) / 2;
    int l_v = max(i * 2, a, m, l, MIN(r, m));
    int r_v = max(i * 2 + 1, m + 1, b, MAX(l, m + 1), r);
    return MAX(l_v, r_v);
}
int build_tree(i, l, r)
        int i, l, r;
{
    if (l != r) {
        int m = l + (r - l) / 2;
        l = build_tree(i * 2, l, m);
        r = build_tree(i * 2 + 1, m + 1, r);
        tree[i] = l > r ? l : r;
    }
    else {
        tree[i] = arr[l];
    }
    return tree[i];
}
void update(l, r, pos, v)
        int l, r, pos, v;
{
    int i = 1;
    while (l != r) {
        int m = l + (r - l) / 2;
        i *= 2;
        if (pos <= m)
            r = m;
        else {
            l = m + 1;
            i += 1;
        }
    }
    tree[i] = v;
    while (i != 1) {
        i /= 2;
        tree[i] = MAX(tree[i * 2], tree[i * 2 + 1]);
    }
}


int main() {
    //freopen("rangemax/input.txt", "r", stdin);
    //freopen("rangemax/output.txt", "w", stdout);
    scanf("%i", &n);
    arr = malloc(sizeof(int) * n);
    tree = malloc(sizeof(int) * 4 * n + 100);
    for (int i = 0; i < n; i++) {
        scanf("%i", arr + i);
    }

    int a = 0, b = n - 1;
    build_tree(1, a, b);

    while (1) {
        char command[10];
        scanf("%s", command);
        int x1, x2;
        scanf("%i%i", &x1, &x2);
        if (!strcmp(command, "MAX"))
            printf("%i ", max(1, a, b, x1, x2));
        else if (!strcmp(command, "UPD"))
            update(a, b, x1, x2);
        else
            break;
    }
    free(tree);
    free(arr);
}