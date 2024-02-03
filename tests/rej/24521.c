#include <stdio.h>
#include <math.h>
int main()
{
	long long x;
	scanf("%lld", &x);
	if (x<0) x*=-1;
    long long s=x%5;
	long long a[s];
	for(int i=0; i<s; i++)
    {
	a[i] = i;
    }
        a[1] = 0;
	for(int i=2; i<s; i++)
    {
		if(a[i]!=0)
        {
			for(int j=i*2; j<s; j+=i)
			{
				a[j]=0;
			}
		}
	}
    long long maxPrime = -1;
    while (x%2 == 0) 
    {
        maxPrime = 2;
        x/=2; 
    }

    while (x%3 == 0) 
    {
        maxPrime = 3;
        x/=3;
    }

    for (int i = 5; i <= sqrt(x); i+=6)
    {
        while (x%i == 0) {
            maxPrime = i;
            x/=i;
        }
        while (x%(i + 2) == 0) {
            maxPrime = i + 2;
            x/=(i + 2);
        }
    }

    if (x > 4)
        maxPrime = x;
	printf("%lld", maxPrime);
    return 0;
}