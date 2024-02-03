#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

union Int32 { 
    int x; 
    unsigned char bytes[4];
};

int main() {
    int n;
    scanf("%d", &n);
    union Int32* arr = malloc(n * sizeof(union Int32));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i].x);
        arr[i].x ^= INT_MIN;
        for (unsigned int j = 0; j < 32; j++) {
            if ((1u << j) & arr[i].x) {
                arr[i].bytes[j / 8] |= (1u << (j % 8));
            }
        }
    }

    int cnt[256];
    int* inds[256];
    int tmps[256];
    int *order = (int*) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        order[i] = i;
    }
    for (int i = 0; i < 256; i++) {
        cnt[i] = 0;
        tmps[i] = 0;
    }
    for (int j = 0; j < 4; j++) {
        for (int i = 0; i < n; i++) {
            cnt[arr[order[i]].bytes[j]]++;
        }
        for (int i = 0; i < 256; i++) {
            inds[i] = (int*) malloc(cnt[i] * sizeof(int));
        }
        for (int i = 0; i < n; i++) {
            inds[arr[order[i]].bytes[j]][tmps[arr[order[i]].bytes[j]]] = order[i];
            tmps[arr[order[i]].bytes[j]]++;
        }
        int idx = 0;
        for (int i = 0; i < 256; i++) {
            for (int k = 0; k < cnt[i]; k++) {
                order[idx] = inds[i][k];
                idx++;
            }
        }

        for (int i = 0; i < 256; i++) {
            cnt[i] = 0;
            tmps[i] = 0;
            free(inds[i]);
        }
    }

    for (int i = 0; i < n; i++) {
        arr[order[i]].x ^= INT_MIN;
        printf("%d ", arr[order[i]].x);
    }
    free(arr);
    free(order);
    return 0;
}