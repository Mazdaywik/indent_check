#include <stdio.h>

int main() {
    int n, k;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }
    scanf("%d", &k);

    long long maxSum = 0;
    long long currentSum = 0;

    for (int i = 0; i < k; ++i) {
        currentSum += arr[i];
    }

    maxSum = currentSum;

    for (int i = k; i < n; ++i) {
        currentSum = currentSum + arr[i] - arr[i - k];
        if (currentSum > maxSum) {
            maxSum = currentSum;
        }
    }

    printf("%lld\n", maxSum);

    return 0;
}