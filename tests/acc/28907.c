#include <stdio.h>
#include <stdlib.h>
int stepen(int n){
	while(n >= 1){
		if(n == 1){
			return 1;
		}
		if((n % 2) == 1){
			return 0;
		}
		else{
			n = n / 2;
		}
	}
	return 0;
}
int loop(int ind, int n, int *a, int kol, int summ){
    if (ind == n){
        return kol;
    }
    return (loop((ind + 1), n, a, 0, summ) + loop((ind + 1), n, a, 0, summ + a[ind]) + (kol + stepen(summ + a[ind])));
}
int main(){
	int n;
	scanf("%d", &n);
	int a[n];
	for (int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	int res = loop(0, n, a, 0, 0);
	printf("%d", res);
	return 0;
}