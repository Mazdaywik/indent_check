#include <stdio.h>
#include <stdlib.h>

int Power2(int x) {
    return x && (!(x & (x - 1)));
}

int main() {
    int n;
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int count = 0;
    for (int mask = 1; mask < (1 << n); mask++) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                sum += arr[i];
            }
        }
        if (Power2(sum)) {
            count++;
        }
    }

    printf("%d", count);

    free(arr);
    return 0;
}