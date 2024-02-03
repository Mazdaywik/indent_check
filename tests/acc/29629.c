#include <stdio.h>

struct Date{
    int Year, Month, Day;
};

int key(struct Date date, int i) {
    int keys[] = {date.Day - 1, date.Month - 1, date.Year - 1970};
    return keys[i];
}

void DistributionSort(struct Date *dates, int base, int n, int index) {
    int count[base];
    for(int i = 0; i < base; i++)
        count[i] = 0;
    for(int i = 0; i < n; i++)
        count[key(dates[i], index)]++;
    for(int i = 1; i < base; i++)
        count[i] += count[i - 1];
    struct Date dates_sorted[n];
    for(int i = n - 1; i >= 0; i--)
        dates_sorted[--count[key(dates[i], index)]] = dates[i];
    for(int i = 0; i < n; i++)
        dates[i] = dates_sorted[i];
}

void radixsort(struct Date *dates, int n){
    int bases[3] = {31, 12, 61};
    for(int i = 0; i < 3; i++)
        DistributionSort(dates, bases[i], n, i);
}


int main() {
    int n;
    scanf("%d", &n);
    struct Date dates[n];
    for(int i = 0; i < n; i++)
        scanf("%d %d %d", &dates[i].Year, &dates[i].Month, &dates[i].Day);
    radixsort(dates, n);
    for(int i = 0; i < n; i++)
        printf("%04d %02d %02d\n", dates[i].Year, dates[i].Month, dates[i].Day);
    return 0;
}