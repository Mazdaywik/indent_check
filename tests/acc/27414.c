#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_YEAR 2030
#define MIN_YEAR 1970
#define MAX_MONTH 12
#define MIN_MONTH 1
#define MAX_DAY 31
#define MIN_DAY 1

typedef struct {
    int day, month, year;
} Date;

int is_leap_year(int year) {
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

int get_key(Date date, int q) {
    switch (q) {
        case 2: return date.day;
        case 1: return date.month;
        case 0: return date.year;
        default: return -1; 
    }
}

void dsort(Date *arr, int n, int q, int max) {
    int count[max + 1];
    memset(count, 0, sizeof(count));
    Date *ans = (Date *)malloc(n * sizeof(Date));

    for (int i = 0; i < n; i++)
        count[get_key(arr[i], q)]++;

    for (int i = 1; i <= max; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        ans[count[get_key(arr[i], q)] - 1] = arr[i];
        count[get_key(arr[i], q)]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = ans[i];

    free(ans);
}

void radixsort(Date *arr, int n) {
    dsort(arr, n, 2, MAX_DAY);  
    dsort(arr, n, 1, MAX_MONTH); 
    dsort(arr, n, 0, MAX_YEAR); 
}

int valid_date(int year, int month, int day) {
    if (year < MIN_YEAR || year > MAX_YEAR ||
        month < MIN_MONTH || month > MAX_MONTH)
        return 0;

    if (day < MIN_DAY || (day > MAX_DAY && !(month == 2 && day == 29)))
        return 0;

    if (month == 2) {
        if (is_leap_year(year)) {
            if (day > 29) return 0;
        } else {
            if (day > 28) return 0;
        }
    }

    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
        return 0;

    return 1;
}

int main() {
    int n;
    scanf("%d", &n);

    Date *dates = (Date *)malloc(n * sizeof(Date));

    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &dates[i].year, &dates[i].month, &dates[i].day);
        if (!valid_date(dates[i].year, dates[i].month, dates[i].day)) {
            printf("Неверная дата: %04d %02d %02d\n", dates[i].year, dates[i].month, dates[i].day);
            free(dates);
            return 1;
        }
    }

    radixsort(dates, n);

    for (int i = 0; i < n; i++) {
        printf("%04d %02d %02d\n", dates[i].year, dates[i].month, dates[i].day);
    }

    free(dates);
    return 0;
}