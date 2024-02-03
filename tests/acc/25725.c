#include <stdio.h>
int main() {
    unsigned long long int n;
    scanf("%llu", &n);
    unsigned long long int f[666];
    f[0] = 1;
    f[1] = 2;
    int k = 0;
    for (int i = 2; i < 666; i++) {
        if((f[i-1] <= n) && (f[i-2] < f[i-1])) {
            f[i] = f[i-1] + f[i-2];
            k++;
        } else {
            break;
        }
    }
    for (int i = 0; i <= k; i++) {
        if(n >= f[k-i]) {
            n -= f[k-i];
            printf("%d", 1);
        } else {
            printf("%d", 0);
        }
    }
}
