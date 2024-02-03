#include <stdio.h>

int main (int argc , char ** argv )
{
    int n, k, sum, max1;
    sum = 0;
    max1 = 0;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++){
        scanf("%d", &a[i]);
        }
    scanf("%d", &k);
    for (int i = 0; i < n; i++){
        if (i < k){
            sum += a[i];
        }
        if (i == k - 1){
            max1 = sum;
        }
        if (i >= k){
            sum = sum + a[i] - a[i - k];
            if (sum > max1){
                max1 = sum;
            }
        }
    }
    printf("%d", max1);
  return 0;
}