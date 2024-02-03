#include <stdio.h>

struct Date {
    int Day, Month, Year;
};

int get_day(struct Date date) { return date.Day; }
int get_month(struct Date date) { return date.Month; }
int get_year(struct Date date) { return date.Year; }

void countSort(struct Date arr[], int n, int rank_max, int (*getField)(struct Date)) {
    int count[10] = {0};
    struct Date output[n];

    for (int rank = 1; rank <= rank_max; rank *= 10) {
        int count[10] = {0};
        struct Date output[n];

        for (int i = 0; i < n; i++) 
            count[(getField(arr[i]) / rank) % 10]++;

        for (int i = 1; i < 10; i++) 
            count[i] += count[i - 1];

        for (int i = n - 1; i >= 0; i--) {
            output[count[(getField(arr[i]) / rank) % 10] - 1] = arr[i];
            count[(getField(arr[i]) / rank) % 10]--;
        }

        for (int i = 0; i < n; i++) 
            arr[i] = output[i];
    }
}

void datesort(struct Date arr[], int n) {
    countSort(arr, n, 100, get_day);
    countSort(arr, n, 100, get_month);
    countSort(arr, n, 1000, get_year);
}

int main() {
    int n;
    scanf("%d", &n);

    struct Date dates[n];
    for (int i = 0; i < n; i++)
        scanf("%d %d %d", &dates[i].Year, &dates[i].Month, &dates[i].Day);

    datesort(dates, n);

    for (int i = 0; i < n; i++) 
        printf("%04d %02d %02d\n", dates[i].Year, dates[i].Month, dates[i].Day);

    return 0;
}
