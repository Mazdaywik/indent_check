#include <stdio.h>

int main() {
    int n, k;
    scanf("%d", &n);
    long arr[n];
    for (int i = 0; i < n; i++)
        scanf("%ld", &arr[i]);
    scanf("%d", &k);
    long s = 0;
    for (int i = 0; i < k; i++)
        s+=arr[i];
    long maxs = s;
    for (int i = k; i < n; i++) {
        s = s - arr[i - k] + arr[i];
        if (s > maxs)
            maxs = s;
    }
    printf("%ld", maxs);
    return 0;
}
