#include <stdio.h>
#include <stdbool.h>

bool step_2(int sum) {
    return (sum != 0) && ((sum & (sum - 1)) == 0);
}

void sumSubsets(int arr[], int n, int index, int currentSum, int *sumk) {
    if (index == n) {
        if (step_2(currentSum)) {
            *sumk += 1;
        }
        return;
    }

    sumSubsets(arr, n, index + 1, currentSum + arr[index], sumk);
    sumSubsets(arr, n, index + 1, currentSum, sumk);
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    int sum = 0;
    sumSubsets(arr, n, 0, 0, &sum);
    printf("%d", sum);
    return 0;
}
