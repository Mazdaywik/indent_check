#include <stdio.h>

int main() {
    unsigned int set_a = 0u, set_b = 0u;
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        unsigned int x;
        scanf("%u", &x);
        set_a |= (1u << x);
    }
    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        unsigned int x;
        scanf("%u", &x);
        set_b |= (1u << x);
    }
    for (unsigned int i = 0; i < 32; i++) {
        if (((1u << i) & set_a) && ((1u << i) & set_b)) {
            printf("%d ", i);
        }
    }
    return 0;
}