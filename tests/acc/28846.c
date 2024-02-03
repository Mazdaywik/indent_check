#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Date {
    int Year, Month, Day;
};

void radixSort(struct Date arr[], int n) {
    const int base = 10;
    int i;
    struct Date *output = malloc(n * sizeof(struct Date));

    // Сортировка по дням
    for (int exp = 1; 31 / exp > 0; exp *= base) {
        int count[base];
        memset(count, 0, sizeof(count));

        for (i = 0; i < n; i++)
            count[(arr[i].Day / exp) % base]++;

        for (i = 1; i < base; i++)
            count[i] += count[i - 1];

        for (i = n - 1; i >= 0; i--) {
            output[count[(arr[i].Day / exp) % base] - 1] = arr[i];
            count[(arr[i].Day / exp) % base]--;
        }

        for (i = 0; i < n; i++)
            arr[i] = output[i];
    }

    // Сортировка по месяцам
    for (int exp = 1; 12 / exp > 0; exp *= base) {
        int count[base];
        memset(count, 0, sizeof(count));

        for (i = 0; i < n; i++)
            count[(arr[i].Month / exp) % base]++;

        for (i = 1; i < base; i++)
            count[i] += count[i - 1];

        for (i = n - 1; i >= 0; i--) {
            output[count[(arr[i].Month / exp) % base] - 1] = arr[i];
            count[(arr[i].Month / exp) % base]--;
        }

        for (i = 0; i < n; i++)
            arr[i] = output[i];
    }
    // Сортировка по годам
    for (int exp = 1; 2030 / exp > 0; exp *= base) {
        int count[base];
        memset(count, 0, sizeof(count));

        for (i = 0; i < n; i++)
            count[(arr[i].Year / exp) % base]++;

        for (i = 1; i < base; i++)
            count[i] += count[i - 1];

        for (i = n - 1; i >= 0; i--) {
            output[count[(arr[i].Year / exp) % base] - 1] = arr[i];
            count[(arr[i].Year / exp) % base]--;
        }

        for (i = 0; i < n; i++)
            arr[i] = output[i];
    }

    free(output);
}

void printDates(struct Date arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%04d %02d %02d\n", arr[i].Year, arr[i].Month, arr[i].Day);
}

int main() {
    int n;
    scanf("%d", &n);

    struct Date *dates = malloc(n * sizeof(struct Date));

    for (int i = 0; i < n; i++)
        scanf("%d %d %d", &dates[i].Year, &dates[i].Month, &dates[i].Day);

    radixSort(dates, n);
    printDates(dates, n);

    free(dates);
    return 0;
}