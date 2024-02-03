#include <stdio.h>

union Int32 {
    int x;
    unsigned char bytes[4];
};

int Key(union Int32 *nums, int c, int i) {
    int key = nums[i].bytes[c];
    if (c == 3) {
        key ^= 128;
    }
    return key;
}

void DistributionSort(union Int32 *mas, int c, int n, int base) {
    int count[base];
    for (int i = 0; i < base; i++) {
        count[i] = 0;
    }
	
    for (int j = 0; j < n; j++) {
        int k = Key(mas, c, j);
        count[k]++;
    }

    for (int i = 1; i < base; i++) {
        count[i] += count[i - 1];
    }
    union Int32 sortedNums[n];

    for (int j = n - 1; j >= 0; j--) {
        int k = Key(mas, c, j);
        int idx = --count[k];
        sortedNums[idx] = mas[j];
    }

    for (int i = 0; i < n; i++) {
        mas[i] = sortedNums[i];
    }
}

void RadixSort(union Int32 *mas, int c, int n, int base) {
    for (int i = 0; i < c; i++) {
	int count[base];

        for (int j = 0; j < base; j++) {
            count[j] = 0;
	}
        DistributionSort(mas, i, n, base);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    union Int32 arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i].x);
    }

    RadixSort(arr, 4, n, 256);

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i].x);
    }
    return 0;
}
