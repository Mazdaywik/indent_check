#include <stdio.h>
#include <math.h>

int main() {

	int a, b,j=0;
	long long int mn_a = 0, mn_b = 0;
	scanf("%d", &a);
	int k1,k2;
	for (int i = 0; i < a; ++i) {
		scanf("%d", &k1);
		mn_a += pow(2, k1);
	}	
	scanf("%d", &b);
	for (int i = 0; i < b; ++i) {
		scanf("%d", &k2);
		mn_b += pow(2, k2);
	}
	while (mn_b > 0 || mn_a>0) {
		if (mn_a % 2 == 1 && mn_b % 2 == 1) {
			printf("%d ", j);
		}
		mn_a /= 2;
		mn_b /= 2;
		j += 1;
	}
	return 0;
}