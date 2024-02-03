#include <stdio.h>
#include <math.h>
int main()
{int x;
int y;
scanf("%d", &x);
scanf("%d", &y);
long p;
long max[x];
long min[y];
for (int i = 0; i<x; i++)
{max[i]= -10000;}
for (int i = 0; i<y; i++)
{min[i]= 10000;}
for (int i = 0; i<x ; i++)
{  
    for (int j = 0; j < y; j++)
    {scanf("%ld", &p);
    if (p > max[i]) {max [i]=p;}
    if (p < min [j]) {min [j] = p;}
    }
}
int w = 0;
for (int i = 0; i<x; i++)
{
for (int j = 0; j<y; j++)
{if (max[i] == min [j])  {printf ("%d", i); printf(" "); printf ("%d", j); w = 1; break;}
}
}
if (w == 0) {printf("none");}
return 0;}
