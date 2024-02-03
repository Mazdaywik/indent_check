#include <stdio.h>
#include <stdlib.h>

unsigned long maxfib(unsigned long n, unsigned long toExclude)
{
	unsigned long fib_1 = 1;
	unsigned long fib_2 = 2;
	unsigned long step = 1;
	
	while (n >= fib_2 || step == toExclude)
	{
		fib_1 = fib_1 + fib_2; // 3 = 1 + 2
		fib_1 = fib_1 + fib_2; // 5 = 3 + 2
		fib_2 = fib_1 - fib_2; // 3 = 5 - 2
		fib_1 = fib_1 - fib_2; // 2 = 5 - 3
		step++;
	}
	
	return fib_1;
}

unsigned long getstep(unsigned long n)
{
	if (n <= 1)
		return 0;
	
	unsigned long fib_1 = 1;
	unsigned long fib_2 = 2;
	
	unsigned long step = 1;
	
	while (fib_2 < n)
	{
		fib_1 = fib_1 + fib_2; // 3 = 1 + 2
		fib_1 = fib_1 + fib_2; // 5 = 3 + 2
		fib_2 = fib_1 - fib_2; // 3 = 5 - 2
		fib_1 = fib_1 - fib_2; // 2 = 5 - 3
		step += 1;
	}
	
	return step;
}

void present(unsigned long step, unsigned long last_step)
{
	unsigned long i = last_step - step;
	if (last_step > step)
		for (i = last_step - step; i > 1; i--)
			printf("0");
	printf("1");
}

int main()
{
	unsigned long a = 0;
	scanf("%lu", &a);
	
	if (a == 0)
	{
		printf("0");
		return 0;
	}
	
	unsigned long step = 0;
	unsigned long last_step = 0;
	unsigned long fib = 0;
	while (a > 0)
	{
		fib = maxfib(a, step);
		
		a -= fib;
		last_step = getstep(fib);
		
		step = step + last_step;      // 5 = 3 + 2
		last_step = step - last_step; // 3 = 5 - 2
		step = step - last_step;      // 2 = 5 - 3
		
		//printf("%lu\n", fib);
		present(step, last_step);
	}
	
	while (step > 0)
	{
		printf("0");
		step--;
	}
	
	return 0;
}