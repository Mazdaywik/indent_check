#include <stdio.h>
#include <math.h>

int main()
{
    int sizeofA, sizeofB, A = 0, B = 0, n;
    int maxA = 0, maxB = 0;
    scanf("%d", &sizeofA);
    for (int i = 0; i < sizeofA; i++)
    {
        scanf("%d", &n);
        if (i == 0)
		    maxA = n;
		else if (n > maxA)
			maxA = n;
        A|=(int) pow(2, n);
    }
    scanf("%d", &sizeofB);
    for (int i=0; i<sizeofB; i++)
    {
        scanf("%d", &n);
         if (i == 0)
		    maxB = n;
		else if (n > maxB)
			maxB = n;
        B|=(int) pow(2, n);
    }
    int C=A&B;
    int minSize = (maxA < maxB) ? maxA : maxB;
    for (int i=0; i<=minSize; i++)
    {
        if ((C & (int) pow(2, i)) != 0)
        {
            printf("%d ", i);
        }
    }
    return 0;
}