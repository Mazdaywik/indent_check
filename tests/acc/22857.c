#include <stdio.h>

int main()
{
	long long n;
	scanf("%lld", &n);
	int c;
	long long fib[91] = {0};
	fib[0] = 1;
	fib[1] = 2;
	fib[2] = 3;
	if (n == 1 | n == 2 | n == 3) {
	    c = n - 1;
	}
	else {
            for (int i = 3; i < 91; i++) {
	        fib[i] = fib[i-1] + fib[i-2];
		c = i;
		if (fib[i] > n){
			c -= 1;
			break;
		}
	    }
	}
	if (n == 0) {
	    printf("%d", 0);
	}
	while (n > 0) {
	    if (n - fib[c] >= 0) {
		n -= fib[c];
		printf("%d", 1);
		c -= 1;
		if (n == 0) {
		    while (c != -1) {
			printf("%d", 0);
			c -= 1;
		    }
		    break;
		}
	    }
	    else {
		c -= 1; 
		printf("%d", 0);
	    }
         }
}