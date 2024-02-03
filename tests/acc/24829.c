#include <stdio.h>
#include <stdbool.h>

bool isPow2(int x) {
    if (x <= 0) {
        return false;
    }
    return (x & (x - 1)) == 0;
}

void genComb(int arr[], int len, int idx, int sum, int *cnt) {
    if (idx == len) {
        return;
    }

    sum += arr[idx];
    if (isPow2(sum)) {
        (*cnt)++;
    }

    genComb(arr, len, idx + 1, sum, cnt);
    genComb(arr, len, idx + 1, sum - arr[idx], cnt);
}

int countComb(int arr[], int len) {
    int cnt = 0;
    genComb(arr, len, 0, 0, &cnt);
    return cnt;
}

int main() {
    int n;
    scanf("%d", &n);

    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int c = countComb(a, n);
    printf("%d\n", c);

    return 0;
}
