#include <stdio.h>
#include <math.h>


int power_two(int n) {
    return (n > 0) && !(n & (n - 1));
}

int count(int count_0, int a[], int length, int i, int sum, int *sum_powers_of_two) {
    if(i == length) {
        if(power_two(sum)) {
            count_0++;
            *sum_powers_of_two += sum;
        }
        return count_0;
    }

    int count_0_without = count(count_0, a, length, i + 1, sum, sum_powers_of_two);
    int count_0_with = count(count_0_without, a, length, i + 1, sum + a[i], sum_powers_of_two);

    return count_0_with;
}

int main() {
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    int ans = 0;
    int sum_powers_of_two = 0;
    
    printf("%d", count(0, a, n, 0, 0, &sum_powers_of_two));
    
    return 0;
}