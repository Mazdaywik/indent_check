#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int lst[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &lst[i]);
    }
    
    int k;
    scanf("%d", &k);

    int summ = 0;
    for (int i = 0; i < k; i++) {
        summ += lst[i];
    }

    int maxx = summ;

    for (int i = k; i < n; i++) {
        summ += lst[i] - lst[i - k];
        if (maxx < summ) {
            maxx = summ;
        }
    }

    printf("%d\n", maxx);

    return 0;
}