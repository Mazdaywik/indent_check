#include <stdio.h>
#include <stdlib.h>

struct Date {
    int Day, Month, Year;
};

int getSortingKey(struct Date date, int part) {
    if (part == 0) return date.Day;
    else if (part == 1) return date.Month;
    else return date.Year - 1970;
}

void sortDates(struct Date *dates, int n, int part, int max_value) {
    int count[max_value + 1];
    struct Date temp[n];
    for (int i = 0; i <= max_value; i++) count[i] = 0;
    for (int i = 0; i < n; i++) count[getSortingKey(dates[i], part)]++;
    for (int i = 1; i <= max_value; i++) count[i] += count[i - 1];
    for (int i = n - 1; i >= 0; i--) {
        int key = getSortingKey(dates[i], part);
        temp[count[key] - 1] = dates[i];
        count[key]--;
    }
    for (int i = 0; i < n; i++) dates[i] = temp[i];
}

void radixSortDates(struct Date *dates, int n) {
    sortDates(dates, n, 0, 31);
    sortDates(dates, n, 1, 12);
    sortDates(dates, n, 2, 60);
}

int main() {
    int n;
    scanf("%d", &n);
    struct Date *dates = (struct Date*) malloc(sizeof(struct Date) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &dates[i].Year, &dates[i].Month, &dates[i].Day);
    }
    radixSortDates(dates, n);
    for (int i = 0; i < n; i++) {
        printf("%04d %02d %02d\n", dates[i].Year, dates[i].Month, dates[i].Day);
    }
    free(dates);
    return 0;
}