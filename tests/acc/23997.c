#include <stdio.h>
#include <math.h>
int main() {
    int N, k;
    scanf("%d", &N);
    int A[N];
    long long s = 0;
    for(int i = 0; i < N; i++) {
    scanf("%d", &A[i]);
    }
    scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		s += A[i];
	}
	long long m = s;
	for (int i = k; i < N; i++) {
        s = s - A[i-k] + A[i];
        m = (m >= s) ? m : s;
    }
    printf("%lld", m);
    return 0;
}