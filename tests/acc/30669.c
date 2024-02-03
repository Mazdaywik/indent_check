#include <math.h>
#include <stdio.h>
#include <stdlib.h>

struct Date {
    int Day, Month, Year;
};

int Key(struct Date d, int r) {
    if (r == 0) {
        return d.Day - 1;
    }
    if (r == 1) {
        return d.Month - 1;
    }
    return d.Year - 1;
}

void DistributionSort(int key, int m, struct Date *d, int n) {
    int *count = (int *)malloc((m + 1) * sizeof(int));
    for (int i = 0; i < m + 1; i++) {
        count[i] = 0;
    }
    int k;
    for (int j = 0; j < n; j++) {
        k = Key(d[j], key);
        count[k]++;
    }

    for (int i = 1; i < m; i++) {
        count[i] += count[i - 1];
    }

    struct Date *D = malloc(sizeof(struct Date) * n);
    int i;
    for (int j = n - 1; j >= 0; j--) {
        k = Key(d[j], key);
        i = count[k] - 1;
        count[k] = i;
        D[i] = d[j];
    }

    for (int y = 0; y < n; y++) {
        d[y] = D[y];
    }
    free(count);
    free(D);
}

int main() {
    int k = 0;
    scanf("%d", &k);
    struct Date dat[k];
    for (int i = 0; i < k; i++) {
        scanf("%d %d %d", &(dat[i].Year), &(dat[i].Month), &(dat[i].Day));
    }
    int m[3] = {31, 12, 2030};
    for (int i = 0; i < 3; i++) {
        DistributionSort(i, m[i], dat, k);
    }

    for (int i = 0; i < k; i++) {
        printf("%04d %02d %02d\n", (dat[i].Year), (dat[i].Month), (dat[i].Day));
    }
    return 0;
}