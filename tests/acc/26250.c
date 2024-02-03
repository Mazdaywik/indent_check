#include <stdio.h>
#define lint long long int

lint maxk(int n, lint arr[], int k) {
    lint sumk = 0;
    for (int i = 0; i < k; i++) {
        sumk += arr[i];
    }
    lint sumkmax = sumk;
    for (int i = k; i < n; i++) {
        sumk += arr[i];
        sumk -= arr[i - k];
        if (sumk > sumkmax) sumkmax = sumk;
    }
    return sumkmax;
}

int main() {
    int n;
    scanf("%d", &n);
    lint arr[n];
    for (int i = 0; i < n; i++) scanf("%lld", &arr[i]);
    int k;
    scanf("%d", &k);
    lint res = maxk(n, arr, k);
    printf("%lld", res);
    return 0;
}