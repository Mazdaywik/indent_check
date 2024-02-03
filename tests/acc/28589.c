#include <stdio.h>
#include <math.h>


int SmartPermut(int i, int sum, int n, int* arr, int c) {

        if (((sum & (sum - 1)) == 0) && sum != 0) {
//        printf("a  %d\n", c);
//        printf("b   %d\n", sum);

        c ++;
    }
    if (i + 1 == n) {
        return c;
    }
    for (int j = i + 1; j < n; j++) {
        c = SmartPermut(j, sum + arr[j], n, arr, c);
    }
    return c;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int c = 0;

for (int i = 0; i < n; ++i) {
        c = SmartPermut (i, arr[i], n, arr, c);
    }
    printf("%d", c);
    return 0;
}