#include <stdio.h>

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return (a < 0) ? -a : a;
}

typedef struct {
    int gcd_value;
} Node;

int query(Node *tree, int left, int right, int query_left, int query_right, int index) {
    if (query_left <= left && right <= query_right) {
        return tree[index].gcd_value;
    }

    if (right < query_left || left > query_right) {
        return 0;
    }

    int mid = (left + right) / 2;
    int left_child = 2 * index + 1;
    int right_child = 2 * index + 2;

    return gcd(query(tree, left, mid, query_left, query_right, left_child),
               query(tree, mid + 1, right, query_left, query_right, right_child));
}

void build_tree(Node *tree, int left, int right, int sequence[], int index) {
    if (left == right) {
        tree[index].gcd_value = sequence[left];
        return;
    }

    int mid = (left + right) / 2;
    int left_child = 2 * index + 1;
    int right_child = 2 * index + 2;

    build_tree(tree, left, mid, sequence, left_child);
    build_tree(tree, mid + 1, right, sequence, right_child);

    tree[index].gcd_value = gcd(tree[left_child].gcd_value, tree[right_child].gcd_value);
}

int main() {
    int n;
    scanf("%d", &n);

    int sequence[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &sequence[i]);
    }

    int m;
    scanf("%d", &m);

    Node tree[4 * n]; 

    build_tree(tree, 0, n - 1, sequence, 0);

    int results[m];
    for (int i = 0; i < m; ++i) {
        int l, r;
        scanf("%d %d", &l, &r);

        results[i] = query(tree, 0, n - 1, l, r, 0);
    }

    for (int i = 0; i < m; ++i) {
        printf("%d\n", results[i]);
    }

    return 0;
}
