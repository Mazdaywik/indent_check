#include <stdio.h>
#include <stdlib.h>

void AllSums(int* arr, int len, int a) {
    arr[len] = a;
    int first_len = len;
    ++len;
    for (int i = 0; i < first_len; i++) {
        arr[len] = a + arr[i];
        ++len;
    }
}

int IsPower2(int n) {
    return ((n & (n - 1)) == 0 && n > 0);
}

int main() {
    int n;
    scanf("%d", &n);

    int len_arr = 1;
    int count = 0;
    for (int i = 1; i < n; i++) {
        len_arr *= 2;
        ++len_arr;
    }
    int* arr = NULL;
    arr = (int*) malloc(len_arr * sizeof(int));
    scanf("%d", &arr[0]);
    int curr_len = 1, k;

    for (int i = 0; i < n-1; i++) {
        scanf("%d", &k);
        AllSums(arr, curr_len, k);
        curr_len = curr_len * 2 + 1;
    }
    
    for (int i = 0; i < len_arr; i++) {
        if (IsPower2(arr[i])) {
            ++count;
        }
    }
    free(arr);
    printf("%d", count);
}