#include <stdio.h>

struct Date {
    int Day, Month, Year;
};

void DistributionSort (int* keys, int m, struct Date dates[], int n) {

    struct Date D[n];
    for (int i = 0; i < n; i++) {
        D[i] = dates[i];
    }
    
    int count[m];
    for (int i = 0; i < m; i++)
    {
        count[i] = 0;
    }
    
    int j = 0;
    while (j < n) {
        int k = keys[j];
        count[k] += 1;
        ++j;
    }
    int i = 1;
    while (i < m) {
        count[i] += count[i-1];
        ++i;
    }
    j = n-1;
    while (j >= 0) {
        int k = keys[j];
        i = count[k]-1;
        count[k] = i;
        dates[i] = D[j];
        --j;
    }
}

void DateSort (struct Date dates[], int n) {

    int keys[3][n];
    int m[] = {31, 12, 2030-1970+1};
    
    for (int i = 0; i <= 2; i++) {
        for (int j = 0; j < n; j++) {
            keys[0][j] = dates[j].Day - 1;
            keys[1][j] = dates[j].Month - 1;
            keys[2][j] = dates[j].Year - 1970;
        }
        DistributionSort(keys[i], m[i], dates, n);
    }
    
    for (int i = 0; i < n; i++)
    {
        printf("%04d %02d %02d\n", dates[i].Year, dates[i].Month, dates[i].Day);
    }
        

}
int main() {
    int n;
    scanf("%d", &n);
    struct Date dates[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d %d %d", &dates[i].Year, &dates[i].Month, &dates[i].Day);
    }
    DateSort (dates, n);
}