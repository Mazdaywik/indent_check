#include <stdio.h>
#include <stdlib.h>

struct Date {
    int Year, Month, Day;
};

int Key(struct Date date, int index) {
    int keys[] = {date.Day - 1, date.Month - 1, date.Year - 1970};
    return keys[index];
}

void countingSort(int base, struct Date *dates, int n, int index) {
    int *count = (int *)malloc(sizeof(int) * base);

    for (int i = 0; i < base; i++) {
        count[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        int k = Key(dates[i], index);
        count[k]++;
    }

    for (int i = 1; i < base; i++) {
        count[i] += count[i - 1];
    }
    struct Date *sortedDates = (struct Date *)malloc(sizeof(struct Date) * n);

    for (int i = n - 1; i >= 0; i--) {
        int k = Key(dates[i], index);
        count[k]--;
        int j = count[k];
        sortedDates[j] = dates[i];
    }

    for (int i = 0; i < n; i++) {
        dates[i] = sortedDates[i];
    }
    free(count);
    free(sortedDates);
}

int main() {
    int n;
    scanf("%i", &n);
    struct Date *dates = (struct Date *)malloc(sizeof(struct Date) * n);

    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &(dates[i].Year), &(dates[i].Month), &(dates[i].Day));
    }
    int bases[] = {31, 12, 61};

    for (int i = 0; i < 3; i++) {
        countingSort(bases[i], dates, n, i);
    }

    for (int i = 0; i < n; i++) {
        printf("%04d %02d %02d\n", dates[i].Year, dates[i].Month, dates[i].Day);
    }
    free(dates);
    return 0;
}
