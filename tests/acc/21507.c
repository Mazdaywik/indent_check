#include <stdio.h>
int main() {
    int n, k;
    long max_sum=0;
    scanf("%d", &n);
    long xs[n];
    for (int i = 0; i < n; ++i) scanf("%ld", &xs[i]);
    scanf("%d", &k);
    for (int i = 0; i < k; ++i) max_sum += xs[i];
    int current_sum = max_sum;
    for (int i = 0; k < n; i++)
    {
        current_sum += xs[k] - xs[i];
        if (current_sum > max_sum) max_sum = current_sum;
        k+=1;
    }
    printf("%ld", max_sum);
    return 0;
}