#include <stdio.h>

struct Date {
    int Day, Month, Year;
};

void dateSort(struct Date arr[], int n) {
    int maxYear = arr[0].Year;
    int maxMonth = arr[0].Month;
    int maxDay = arr[0].Day;

    for (int i = 1; i < n; i++) {
        if (arr[i].Year > maxYear) {
            maxYear = arr[i].Year;
        }
        if (arr[i].Month > maxMonth) {
            maxMonth = arr[i].Month;
        }
        if (arr[i].Day > maxDay) {
            maxDay = arr[i].Day;
        }
    }

    for (int exp = 1; maxDay / exp > 0; exp *= 10) {
        int count[10] = {0};
        struct Date res[n];

        for (int i = 0; i < n; i++) {
            count[(arr[i].Day / exp) % 10]++;
        }

        for (int i = 1; i < 10; i++) {
            count[i] += count[i - 1];
        }

        for (int i = n - 1; i >= 0; i--) {
            res[count[(arr[i].Day / exp) % 10] - 1] = arr[i];
            count[(arr[i].Day / exp) % 10]--;
        }

        for (int i = 0; i < n; i++) {
            arr[i] = res[i];
        }
    }

    for (int exp = 1; maxMonth / exp > 0; exp *= 10) {
        int count[10] = {0};
        struct Date res[n];

        for (int i = 0; i < n; i++) {
            count[(arr[i].Month / exp) % 10]++;
        }

        for (int i = 1; i < 10; i++) {
            count[i] += count[i - 1];
        }

        for (int i = n - 1; i >= 0; i--) {
            res[count[(arr[i].Month / exp) % 10] - 1] = arr[i];
            count[(arr[i].Month / exp) % 10]--;
        }

        for (int i = 0; i < n; i++) {
            arr[i] = res[i];
        }
    }

    for (int exp = 1; maxYear / exp > 0; exp *= 10) {
        int count[10] = {0};
        struct Date res[n];

        for (int i = 0; i < n; i++) {
            count[(arr[i].Year / exp) % 10]++;
        }

        for (int i = 1; i < 10; i++) {
            count[i] += count[i - 1];
        }

        for (int i = n - 1; i >= 0; i--) {
            res[count[(arr[i].Year / exp) % 10] - 1] = arr[i];
            count[(arr[i].Year / exp) % 10]--;
        }

        for (int i = 0; i < n; i++) {
            arr[i] = res[i];
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    struct Date dates[n];

    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &dates[i].Year, &dates[i].Month, &dates[i].Day);
    }

    dateSort(dates, n);

    for (int i = 0; i < n; i++) {
        printf("%04d %02d %02d\n", dates[i].Year, dates[i].Month, dates[i].Day);
    }

    return 0;
}