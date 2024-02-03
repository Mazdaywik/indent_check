#include <stdio.h>

int power2(int n)
{
    return n <= 0 ? 0 : !(n & (n - 1));
}

void rec_power(int index, int sum, int n, int* arr, int* res) {
    if (power2(sum))
        (*res)++;
    if (index + 1 == n)
        return;
    for (int i = index + 1; i < n; ++i)
        rec_power(i, sum + arr[i], n, arr, res);
}


int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }
    int ans = 0;
    for (int i = 0; i < n; ++i)
        rec_power(i, arr[i], n, arr, &ans);
    printf("%d\n", ans);
    return 0;
}