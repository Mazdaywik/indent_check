#include <stdio.h>

int main() {
    unsigned long long a, b, m;
    scanf("%lld", &a);
    scanf("%lld", &b);
    scanf("%lld", &m);
    int arr[64];
    int k = 0;
    while (b>0) {
        arr[k] = b % 2;
        b /= 2;
        k += 1;
    }
    for (int i = k; i < 64; i++)
        arr[i] = 0;
    a=a % m;
    unsigned long long res = (a * (arr[63] % m)) % m;
    for (int i = 62; i >= 0; i--)
        res=((res * (2 % m)) % m +(a * (arr[i] % m)) % m) % m;
    printf("%lld", res);
    return 0;
}
