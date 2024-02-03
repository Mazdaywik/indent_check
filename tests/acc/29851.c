#include <stdio.h>
#include <stdlib.h>

int isPowerOfTwo(int n) {
    return (n > 0) && ((n & (n - 1)) == 0);
}

int countCombinations(int arr[], int n, int sum, int index) {
    if (index < 0) {
        return isPowerOfTwo(sum);
    }
    int include = countCombinations(arr, n, sum + arr[index], index - 1);
    int exclude = countCombinations(arr, n, sum, index - 1);

    return include + exclude;
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }

    printf("%d\n", countCombinations(arr, n, 0, n - 1));

    return 0;
}
