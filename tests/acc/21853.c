#include <stdio.h>
#include <stdlib.h>
int main(int argc, char** argv)
{ 
    int l, k;
    scanf("%d", &l);
    long long *a = (long long*)calloc(l, sizeof(long long));
    for (int i=0; i < l; i++) {
        scanf("%lld", &a[i]);
    }
    scanf("%d", &k);
    long long sumk = 0, res = -(1LL << 62);
    for (int i=0; i < l; i++){
        sumk += a[i];
        if (i > k-1) sumk -= a[i-k];
        if (i >= k-1 && sumk > res) res = sumk;
    }
    printf("%lld", res);
    free(a);
	return 0;
}