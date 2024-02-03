#include <stdio.h>
int main(int argc, char ** argv) {
    long long N, x0, sum = 0, dif = 0;
    scanf("%lld", &N);
    scanf("%lld", &x0);
    long long a[N+1];
    for(int i = 0; i < N; i++) {
        scanf("%lld", &a[i]);
        sum = (sum + a[i]) * x0;
        if(i == N - 1) {
        dif = dif + a[i];
        } else {
        dif = (dif + a[i] * (N - i)) * x0;
        }
    }
    scanf("%lld", &a[N]);
    sum += a[N];
    printf("%lld", sum);
    printf(" ");
    printf("%lld", dif);
    return 0;
}
