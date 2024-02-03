#include <stdio.h>
#include <stdlib.h>
int arr[5]={0,1,4,4,1};
int less(unsigned long i, unsigned long j){if (arr[i]<arr[j]) return 1; return 0;}
unsigned long peak(unsigned long nel,
        int (*less)(unsigned long i, unsigned long j))
{if (nel==1){return 0;}
   if (less(0,1)==0) return 0; if (less(nel-1,nel-2)==0) return nel-1;
   for (int i=1; i<nel-1; i++) if ((less(i,i-1)==0)&&(less(i,i+1)==0)) return i;
}
int main()
{
    printf("%ld", peak(5,less));
}
