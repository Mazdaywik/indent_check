// не подсказано, просто задача похожа на егэшные 

#include <stdio.h> 

int main(char argc, char **argv) {

    int n, k;
    scanf("%d", &n);
    
    long long int numbers[n];
    
    for (int i = 0; i < n; i++) scanf("%lld", &numbers[i]);
    scanf("%d", &k);

    long long int sumk = 0;

    for (int ind = n - 1; ind >= (n - k); ind--) sumk += numbers[ind];

    long long int maxsum = sumk;

    for (int ind = (n - k - 1); ind >= 0; ind--) {
        sumk = sumk - numbers[ind + k] + numbers[ind];
        if (sumk > maxsum) maxsum = sumk;
    }

    printf("%lld", maxsum);

    return 0;

}