#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    int *arr;
    arr = (int*) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int answer = 0;
    for (int mask = 0; mask < (1 << n); mask++) {
        int summ = 0;
        for (int i = 0; i < n; i++) {
            if ((1 << i) & mask) {
                summ += arr[i];
            }
        }
        if (summ >= 1) {
            int ok = 1;
            while (summ > 1) {
                if (summ % 2 == 1) {
                    ok = 0;
                    break;
                }
                summ /= 2;
            }
            if (ok) {
                answer++;
            }
        }
    }
    printf("%d\n", answer);
    free(arr);
}