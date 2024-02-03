#include <stdio.h>

unsigned long powa(int i,int j)
{
    int k = 1;
    while (j!=0) {
        k = k*i;
	j--;
    }
    return k;
}

int main()
{
	unsigned long a = 0, b = 0;
	int n, m;
	scanf("%d", &n);
	int elem;
	unsigned long mx = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &elem);
		mx = elem >= mx ? elem : mx;
		a += powa(2, elem);
	}
	
	scanf("%d", &m);
	
	for (int i = 0; i < m; i++) {
		scanf("%d", &elem);
		mx = elem >= mx ? elem : mx;
		b += powa(2, elem);
	}
	unsigned long c = a & b;
	int mn = m <= n ? m : n;
        int pointer = mn - 1;
	int arr[mn];
	for (int i = 0; i < mn; i++) {
		arr[i] = 32;
	}
	for (int i = 0; i < mx; i++) {
		if (c >= (powa(2,mx-i))) {
			arr[pointer] =  mx - i;
                        pointer -= 1;
			c -= powa(2, mx-i) ;
		}
		if (c == 1) {
			arr[0] = 0;
			break;
		}
	}
	for (int i = 0; i < mn; i++){
		if (arr[i] != 32){
		    printf("%d ", arr[i]);
                }
	}
}