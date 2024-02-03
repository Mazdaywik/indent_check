#include <stdio.h>
int main(int argc, char **argv){
	long long x;
	scanf("%lld", &x);
	long long fib1 = 0, fib2 = 1, fib = 1;
	long long p;
	if (x == 0){
		printf("%d", 0);
	}
	else if (x == 1){
		printf("%d", 1);
	}
	else{
		while ((fib + fib2) <= x){
			p = fib;
			fib = fib + fib2;
			fib1 = fib2;
			fib2 = p;
		}
		short res = 0;
		long long t = x;
		while (fib > 0){
			if(x >= fib){
				printf("%d", 1);
				res = 1;
				x = x - fib;
				if(fib == 3){
					fib = 1;
					fib1 = 0;
					fib2 = 1;
					printf("%d", 0);
				}
				else if(fib == 1){
					fib = 0;
				}
				else if(fib == 2){
					fib = 0;
					printf("%d", 0);
				}
				else{
					fib = fib1;
					fib2 = fib2 - fib1;
					fib1 = fib1 - fib2;
					printf("%d", 0);
				}
			}
			else{
				if(res == 1){
					printf("%d", 0);
				}
				if(fib == 1){
					fib = 0;
				}
				else if(fib == 2){
					fib = 1;
					fib1 = 0;
					fib2 = 1;
				}
				else{
					fib = fib2;
					fib1 = fib2 - fib1;
					fib2 = fib2 - fib1;
				}
	}}}
	return 0;
}