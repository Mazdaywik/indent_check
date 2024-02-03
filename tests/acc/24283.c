#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

char s[1000001];
char p[1000001];
int *t;

void update(int v, int l, int r, int idx, int x) {
    if (l + 1 == r) {
        t[v] = x;
        return;
    }
    int mid = (l + r) / 2;
    if (idx < mid) {
        update(2 * v + 1, l, mid, idx, x);
    } else {
        update(2 * v + 2, mid, r, idx, x);
    }
    t[v] = (t[2 * v + 1] ^ t[2 * v + 2]);
}

int get_xor(int v, int l, int r, int a, int b) {
    if (b <= l || r <= a) {
        return 0;
    }
    if (a <= l && r <= b) {
        return t[v];
    }
    int mid = (l + r) / 2;
    return (get_xor(2 * v + 1, l, mid, a, b) ^ get_xor(2 * v + 2, mid, r, a, b));
}

int main() {
    scanf("%s", &s);
    int n = strlen(s);
    t = (int*) malloc(4 * n * sizeof(int));
    for (int i = 0; i < n; i++) {
        update(0, 0, n, i, (1 << (s[i] - 'a')));
    }
    while (1) {
        char type[4];
        scanf("%s", &type);
        if (type[0] == 'H') {
            int l, r;
            scanf("%d%d", &l, &r);
            int res = get_xor(0, 0, n, l, r + 1);
            int cnt = 0;
            for (int i = 0; i < 26; i++) {
                if ((1 << i) & res) {
                    cnt++;
                }
            }
            if (cnt <= 1) {
                printf("YES\n");
            } else {
                printf("NO\n");
            }
        } else if (type[0] == 'U') {
            int idx;
            scanf("%d %s", &idx, &p);
            int len = strlen(p);
            for (int j = 0; j < len; j++) {
                s[idx + j] = p[j];
                update(0, 0, n, idx + j, (1 << (s[idx + j] - 'a')));
            }
        } else {
            break;
        }
    }
    free(t);
    return 0;
}