#include <stdio.h>
int main(void) {
    int size;
	scanf("%d", &size);
    long long a[size];
	long long t1, t2;
	long long h=0;
	for (int i = 0; i < size; i++)
		{scanf("%lld", &a[i]);}
	int k;
	scanf("%d", &k);
	long long max_sum =0;
    for (int i = 0; i < size; i++)
		{
		if (i < k) {h = h+a[i]; max_sum = h;}
		else{
			if(i == k) {max_sum = h;}
			t1 = a[i-k];
			t2 = a[i];
			h = h-t1+t2;
			if (max_sum < h) {max_sum = h;}
			}
		}
	printf("%lld", max_sum);
	




  return (0);
}