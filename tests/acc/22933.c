#include <stdio.h>
int main(int argc, char **argv)
{
    int size, k, i;
    scanf("%d", &size);
    long arr[size], sum = 0, maxsum;
    for (i = 0; i < size; i++) {
        scanf("%ld", &arr[i]);
    }
    scanf("%d", &k);
    for (i = 0; i < k; i++) {
        sum += arr[i];
    }
    maxsum = sum;
    for (i = k; i < size; i++) {
        sum = sum + arr[i] - arr[i - k];
        if (sum > maxsum) maxsum = sum;
    }
    printf("%ld", maxsum);
    return 0;
}