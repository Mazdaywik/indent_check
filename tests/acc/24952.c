#include <stdio.h>

int main() {
    int n, k;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    scanf("%d", &k);

    int maxSum = 0;
    int startIndex = 0;


    for (int i = 0; i < k; i++) {
        maxSum += arr[i];
    }

    int currentSum = maxSum;

    for (int i = k; i < n; i++) {
        currentSum += arr[i] - arr[i - k]; 
        if (currentSum > maxSum) { 
            maxSum = currentSum;
            startIndex = i - k + 1;
        }
    }

    printf("%d\n", maxSum);

    return 0;
}