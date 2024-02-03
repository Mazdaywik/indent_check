#include <stdio.h>

int main(int argc, char **argv) {
    unsigned long x;
    scanf("%lu", &x);
    if (x==0) printf("%d", 0);
    else {
        unsigned long a[94], i = 1;
        a[0]=1;
        a[1]=2;
        while (x >= a[i]) {
            i++;
            a[i] = a[i - 1] + a[i - 2];
        }
        for (unsigned long j = i-1; j != (unsigned long)-1; j--) {
            if (x >= a[j]) {
                printf("%d", 1);
                x -= a[j];
            } 
            else printf("%d", 0);
        }
    }
    return 0;
}