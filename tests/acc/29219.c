#include <stdio.h>
int main()
{
	int n;
	long long x0;
	scanf("%d %lld", &n, &x0);
	long long koef[n+1];
	for(int i = n; i >= 0; i--){
		scanf("%lld", &koef[i]);
	}
	long long znach;
	long long proizv;
	for(int i = n-1; i >= 0; i--){
		if(i == (n-1)){
			znach = koef[i+1] * x0 + koef[i];
			proizv = koef[i+1] * n * x0 + koef[i] * (n-1);
		}
		else if(i == 0){
			znach = znach * x0 + koef[i];
		}
		else{
			znach = znach * x0 + koef[i];
			proizv = proizv * x0 + koef[i] * i;
		}
	}
	printf("%lld\n%lld\n", znach, proizv);
	return 0;
}