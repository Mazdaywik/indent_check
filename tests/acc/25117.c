#include <stdio.h>
int main() {
	int A, B;
	unsigned long int a = 0, b = 0, e = 1;
	scanf("%d", &A);
	for (int i = 0; i < A; i++) {
		int x;
		scanf("%d", &x);
		a += (1 << x);
	}
	scanf("%d", &B);
	for (int i = 0; i < B; i++) {
		int x;
		scanf("%d", &x);
		b += (1 << x);
	}
	long int c = a & b;
	for(int i = 0; i <= 31; i++) {
	  if((c / (e << i)) % 2 == 1) {
	    printf("%d", i);
	    printf("%s", " ");
	  }
	}
}