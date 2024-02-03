#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
int main(){
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    int sum = 0, ans = 0, j, count;
    for (int i = 1; i < (1 << n); i++){
        sum = 0;
        j = i;
        count = 0;
        while (j > 0){
            if (j & 1)
               sum += a[count];
            j = j >> 1;
            count += 1;
        }
        if ((sum > 0) && ((sum & (sum - 1)) == 0))
            ans += 1;
    }
    printf("%d", ans);
}