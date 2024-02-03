#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(){
	long n;
	scanf("%ld", &n);
	long a[n], b[n];
	for (long i = 0; i < n; i++){
		scanf("%ld/%ld", &a[i], &b[i]);
	}
	long l = 0, r = 0;
	float maximum = log2(a[0]) - log2(b[0]);
	long start = 0, i = 0;
	float  proiz = 0;
	while (i < n){
		proiz = proiz + log2(a[i]) - log2(b[i]);
		if(proiz > maximum){
			maximum = proiz;
			l = start;
			r = i;
		}
		i = i + 1;
		if (proiz < 0){
			proiz = 0;
			start = i;
		}
	}
	printf("%ld %ld", l, r);
}