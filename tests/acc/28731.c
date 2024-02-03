#include <stdio.h>
#include <stdlib.h>

long long stage1(long long n)
{
	long long fib1 = 1, fib2 = 2, fib3;
	while (fib2 <= n)
	{
		fib3 = fib1 + fib2;
		fib1 = fib2;
		fib2 = fib3;
	}

	return fib1;
}

long long stage2(long long n)
{
	long long fib1 = 1, fib2 = 2, fib3, k = 1;
	while (fib2 <= n)
	{
		fib3 = fib1 + fib2;
		fib1 = fib2;
		fib2 = fib3;
		k++;
	}

	return k;
}

int main()
{
	long long n;
	scanf("%lld", &n);
	if (n == 0) printf("0");
	else
	{
		long long ma = stage2(n), arr[ma];
		for (long long i = 0; i < ma; i++)
		{
			arr[i] = 0;
		}

		while (n > 0)
		{
			arr[stage2(n)] = 1;
			n -= stage1(n);
		};

		int res[ma];
		res[ma - 1] = 1;
		for (long i = 1; i <= ma - 1; i++)
		{
			res[i - 1] = arr[i];
		}	//здесь вывод именно начиная с первого числа Фибоначчи, если это не так, то просто реверс
		for (int i = ma - 1; i >= 0; i--)
			printf("%d", res[i]);
	}
}