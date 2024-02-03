#include <stdio.h>
int main(int argc, char** argv)
{ 
    long long x;
    int len = 1;
    scanf("%lld", &x);
    long long a = 1, b = 1, c;
    while (x - b - a >= 0){
        c = a + b;
        a = b;
        b = c;
        ++len;
    }
    int res[len];
    for(int i=0; i < len; i++) res[i] = 0;
    if (x != 0) res[len-1] = 1;
    x -= b;
    while (x > 0){
        int k = 0;
        long long a = 1, b = 1, c;
        while (x - b - a >= 0){
            c = a + b;
            a = b;
            b = c;
            ++k;
        }
        if (res[k+1] == 1) {
            --k;
            x -= a;
        }
        res[k] = 1;
        x -= b;
    }
    for(int i=len-1; i >= 0; i--) printf("%d", res[i]);
    return 0;
}