#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#define END_ARRAY (10e6 + 1)

int foo(num, ind, ans, sum)
    int *num, ind, ans, sum;
{
    sum += num[ind];
    ind++;
    if (sum && !(sum & (sum - 1))) {
        ++ans;
    }
    return num[ind] == END_ARRAY ?
        ans :
        ans + foo(num, ind, 0, sum) + foo(num, ind, 0, sum - num[ind - 1]);
}
int main()
{
    uint64_t n;
    int a[25];
    scanf("%zu", &n);
    a[n] = END_ARRAY;
    for (uint64_t i = 0; i < n; i++) {
        scanf("%i", a + i);
    }
    printf("%i", foo(a, 0, 0, 0));
}