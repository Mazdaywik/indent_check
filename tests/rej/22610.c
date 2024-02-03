#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(){
	long long x;
	scanf("%lld", &x);
	long long z = llabs(x);
	long long y = sqrt(z) + 1;
	int prime[y];
	for (long long i = 0; i < y; i++){
		prime[i] = 1;
	}
	long long primedel = 1;
	for (long long i = 2; i <= y; i++){
		if((z % i) == 0){
			z = z / i;
		if (prime[i] == 1){
				primedel = i;
			}
			for (long long j = (i * i); j <= y; j += i){
				prime[j] = 0;
	}}}
	if (z <= y){
		printf("%lld", primedel);
	}
	else{
		printf("%lld", z);
	}
	return 0;
}