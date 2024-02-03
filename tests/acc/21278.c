#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <math.h>

int main() {
	unsigned long long x,f=1,s=1,m,g;
	scanf("%llu", &x);
	unsigned long long arr[91];
	for (int i = 0; i < 91; ++i) {
		arr[i] = s;
		m = f;
		f = s;
		s = m + f;
	}
	g = x;
	int res[91] = { 0 };
	int max_i = -1;
	while (x > 0) {
		unsigned long long h = 0;
		int id = 0;
		for (int i = 0; i < 91; ++i) {
			if (arr[i] > x) {
				h = arr[i-1];
				id = i-1;
				if (id > max_i) {
					max_i = id;
				}
				break;
				
			}
			if (i == 90) {
				h = arr[i];
				id = i;
				if (id > max_i) {
					max_i = id;
				}
			}
		}
		x -= h;
		res[id] = 1;
	}
	if (g != 0) {
		for (int i = max_i; i > -1; --i) {
			printf("%d", res[i]);
		}
	}
	else
	{
		printf("0");
	}
}