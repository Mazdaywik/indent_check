#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <assert.h>

#define N 1000001

typedef struct {
    int sum;
    int value;
} elem;

int build(char v[], int n, int l, int r, elem * T) {
    assert(T != NULL);

    int sum = 0;
    int bound = fmin(r, n);

    while (l < bound) {
        int m = (l + r) / 2;
        sum ^= build(v, n, l, m, T);
        l = m + 1;
    }

    if (r < n) {
        sum ^= (1L << (v[r] - 'a'));
        T[r].sum = sum;
        T[r].value = (1L << (v[r] - 'a'));
    }

    return sum;
}

int query_i(int i, elem * T) {
    assert(T != NULL);

    int v = 0;
    while (i >= 0) {
        v ^= T[i].sum;
        i = (i & (i + 1)) - 1;
    }
    return v;
}

int query(int l, int r, elem * T) {
    assert(T != NULL);
    return query_i(r, T) ^ query_i(l-1, T);
}

void update(int i, char delta, int n, elem * T) {
    assert(T != NULL);

    int j = i, dshift = (1 << (delta - 'a'));

    while (i < n) {
        T[i].sum = T[i].sum ^ dshift ^ T[j].value;
        i = i | (i + 1);
    }

    T[j].value = dshift;
}

int main() {
    char a[N]; scanf("%s", a);
    int n = strlen(a);

    int r = (n == 1 ? 1 : 1 << ((int)log2(n-1)+1));
    elem * T = (elem *)calloc(n, sizeof(elem));
    build(a, n, 0, r-1, T);

    char s[4] = {0};

    while (1) {
        scanf("%s", s);
        if (s[0] == 'E') {
            break;
        } else if (s[0] == 'H') {
            int l, r;
            scanf("%d %d", &l, &r);
            int result = query(l, r, T);
            printf("%s\n", (!(result & (result - 1)) ? "YES" : "NO"));
        } else if (s[0] == 'U') {
            int i; char v[N];
            scanf("%d %s", &i, v);
            for (int j = 0; v[j] != 0; ++j)
                update(i+j, v[j], n, T);
        }
    }

    free(T);

    return 0;
}