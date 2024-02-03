#include <stdio.h>
#include <math.h>



long power2(int *s, size_t n, int ind, long sum) {
    if (ind == n) {
        while (sum % 2 == 0 && sum > 0 && sum != 1){
            sum = sum / 2;
        }
        if (sum == 1) return 1;
        else return 0;
    }
    else {
        return power2(s, n, ind + 1, sum) + power2(s, n, ind + 1, sum + s[ind]);
    }
}


int main()
{
    int n = 0;
    scanf("%d", &n);
    int s[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &s[i]);
    }
    long res = power2(s, n, 0, 0);
    printf("%ld", res);
    return 0;
}