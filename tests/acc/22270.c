#include <stdio.h>
#include <math.h>

void Negative(long long *n) {
	if (*n < 0) {
	    *n *= -1;
	}
}


int main() {
    long long x, p;
    scanf("%lld", &x);
    
    Negative(&x);
    
    p = sqrt(x)+1;
    char lst[p];
    for (int i = 0; i < p; i++) {
        lst[i] = 1;
    }
    
    
    lst[0] = 0;
    lst[1] = 0;
    long long a = 0;
    for (int i = 2; i < p; i++) {
        if (lst[i] == 1) {
            for (int j = i * i; j < p; j += i) {
                lst[j] = 0;
            }
            if (x % i == 0) {
                while (x % i == 0) {
                    x /= i;
                    if (i > a) {
                    a = i;
                    }
                }
            }
        }
    }

    if (x > a) {
        a = x;
    }
    
    printf("%lld\n", a);

    return 0;
}