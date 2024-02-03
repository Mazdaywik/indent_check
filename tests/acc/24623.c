#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void sort(int l, int r, int *arr) {
    if (r - l + 1 <= 1) {
        return;
    }
    int mid = arr[(l + r) / 2];
    int tmp1 = l, tmp2 = r;
    while (tmp1 <= tmp2) {
        while (arr[tmp1] < mid) {
            tmp1++;
        }
        while (arr[tmp2] > mid) {
            tmp2--;
        }
        if (tmp1 >= tmp2) {
            break;
        }
        int x = arr[tmp1];
        arr[tmp1] = arr[tmp2];
        arr[tmp2] = x;
        tmp1++, tmp2--;
    }
    sort(l, tmp2, arr);
    sort(tmp2 + 1, r, arr);
}

int main(int argc, char* argv[]) {
    int n;
    scanf("%d", &n);
    int* arr = (int*) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int *pref = (int*) malloc((n + 1) * sizeof(int));
    pref[0] = 0;
    for (int i = 0; i < n; i++) {
        pref[i + 1] = (pref[i] ^ arr[i]);
    }
    long long ans = 0;
    sort(0, n, pref);
    int i = 0;
    while (i <= n) {
        int j = i;
        while (j <= n && pref[i] == pref[j]) {
            j++;
        }
        long long cnt = j - i;
        ans += cnt * (cnt - 1) / 2;
        i = j;
    }
    printf("%lld", ans);
    free(arr);
    free(pref);
}