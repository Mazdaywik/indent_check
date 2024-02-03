#include <stdio.h>
#include <stdlib.h>

struct Date {
    int Day, Month, Year;
};

int getDigit(struct Date date, int exp) {
    if (exp == 0) return date.Day % 10;
    else if (exp == 1) return (date.Day / 10) % 10;
    else if (exp == 2) return date.Month % 10;
    else if (exp == 3) return (date.Month / 10) % 10;
    else if (exp == 4) return date.Year % 10;
    else if (exp == 5) return (date.Year / 10) % 10;
    else if (exp == 6) return (date.Year / 100) % 10;
    else if (exp == 7) return (date.Year / 1000) % 10;
    else return 0;
}

void radixSort(struct Date* arr, int n) {
    const int base = 10; // Основание системы счисления
    struct Date* output = (struct Date*)malloc(n * sizeof(struct Date));
    int count[10] = { 0 };

    for (int exp = 0; exp < 8; exp++) {
        for (int i = 0; i < 10; i++)
            count[i] = 0;

        for (int i = 0; i < n; i++)
            count[getDigit(arr[i], exp)]++;

        for (int i = 1; i < base; i++)
            count[i] += count[i - 1];

        for (int i = n - 1; i >= 0; i--) {
            output[count[getDigit(arr[i], exp)] - 1] = arr[i];
            count[getDigit(arr[i], exp)]--;
        }

        for (int i = 0; i < n; i++)
            arr[i] = output[i];
    }

    free(output);
}

int main() {
    int n;
    scanf("%d", &n);

    struct Date* dates = (struct Date*)malloc(n * sizeof(struct Date));

    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &dates[i].Year, &dates[i].Month, &dates[i].Day);
    }

    radixSort(dates, n);

    for (int i = 0; i < n; i++) {
        printf("%04d %02d %02d\n", dates[i].Year, dates[i].Month, dates[i].Day);
    }

    free(dates);
    return 0;
}