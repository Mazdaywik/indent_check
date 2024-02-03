#include <stdio.h>
int fibfind(unsigned long long x, int n, unsigned long long a, unsigned long long b);
int main() {
    unsigned long long z;
    scanf("%lld", &z);
    int k = fibfind(z,0,1,1);
    unsigned long long arr[k];
    unsigned long long a=1;
    unsigned long long b=1;
    for (int i = 0; i<k; i++) {
        arr[i] = b;
        b += a;
        a = arr[i];
    }

    if (z > 0) {
        for (int i = k-1; i>=0; i--){
            if (arr[i] <= z) {
                printf("%d", 1);
                z -= arr[i];
            }
            else {
                printf("%d", 0);
            }
        }
    }
    else 
        printf("%d", 0);
    
    return 0;
}
int fibfind(unsigned long long x, int n, unsigned long long a, unsigned long long b) {
    if (b <= x) 
        fibfind(x, n + 1, b, a+b);
    else 
        return n;
}
   