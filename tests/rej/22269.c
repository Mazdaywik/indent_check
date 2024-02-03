#include <stdio.h>
#include <math.h>

int main()
{
unsigned long a, b, m;
unsigned long px0;

scanf("%lu", &a);
scanf("%lu", &b);
scanf("%lu", &m);

unsigned long n = (unsigned long)(log2(b)) + 1;

int b_2[n];
unsigned long temp_b = b;
int i = 0;
while (i < n)
{
b_2[i] = temp_b % 2;
temp_b = temp_b / 2;
i++;
}

px0 = b_2[n - 1] * a % m;

int j = n - 2;
while (j >= 0)
{
px0 = ((px0 * 2) % m + b_2[j] * (a % m)) % m;
j--;
}

printf("%lu", px0);

return 0;
}
