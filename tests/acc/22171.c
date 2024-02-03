#include <stdio.h>
int main(int argc, char** argv)
{
    int n;
    long long x0;
    scanf("%d %lld", &n, &x0);
    long long derriv = 0, res = 0;
    for(int i=0; i <= n; i++){
        long long k;
        scanf("%lld", &k);
        derriv = derriv*x0 + res;
        res = res*x0 + k;
    }
    printf("%lld%s%lld", res, " ", derriv);
	return 0;
}