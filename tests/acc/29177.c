/* 1st semester, 2nd module, task 10
 * datesort
 * counting sort for structures, radix sort
 * "Now program uses radix sort"
 * */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <stdint.h>
#include <string.h>

void swap(void* a, void* b, void* t, size_t width){
    // Such things should be done on stack. That is why people should C++ templates instead of this whatever
    memcpy(t, a, width);
    memcpy(a, b, width);
    memcpy(b, t, width);
}

typedef struct{
    int Day, Month, Year;
} Date;

static const int day_limit = 31;
static const int month_limit = 12;
static const int year_first = 1970;
static const int year_last = 2030;

int rds_get_date_day_i(const Date* d){
    return d->Day - 1;
}

int rds_get_date_month_i(const Date* d){
    return d->Month - 1;
}

int rds_get_date_year_i(const Date* d){
    return d->Year - year_first;
}

void radix_sort_part(Date* arr, int n, int(*get_i_fnc)(const Date*), int m){
    int* sizes = calloc(m, sizeof(int));  // sizes[i] = 0
    for (int i = 0; i < n; i++){
        int v = get_i_fnc(&arr[i]);
        assert(v < m);
        sizes[v]++;
    }
    Date** B = calloc(m, sizeof(Date*));
    for (int i = 0; i < m; i++){
        B[i] = calloc(sizes[i], sizeof(Date));
        sizes[i] = 0; // Reusing this array
    }
    for (int i = 0; i < n; i++){
        int v = get_i_fnc(&arr[i]);
        B[v][sizes[v]] = arr[i];
        sizes[v]++; // array restored
    }
    int p = 0;
    for (int i = 0; i < m; i++){
        for (int j = 0; j < sizes[i]; j++){
            arr[p] = B[i][j];
            p++;
        }
    }
    assert(p == n);
    for (int i = 0; i  < m; i++){
        free(B[i]);
    }
    free(B);
    free(sizes);
}

int main(){
    int n;
    scanf("%d", &n);
    Date* dates = calloc(n, sizeof(Date));
    for (int i = 0; i < n; i++){
        scanf("%d %d %d", &dates[i].Year, &dates[i].Month, &dates[i].Day);
        assert(1 <= dates->Day && dates->Day <= day_limit);
        assert(1 <= dates->Month && dates->Month <= month_limit);
        assert(year_first <= dates->Year && dates->Year <= year_last);
    }
    radix_sort_part(dates, n, &rds_get_date_day_i, day_limit);
    radix_sort_part(dates, n, &rds_get_date_month_i, month_limit);
    radix_sort_part(dates, n, &rds_get_date_year_i, year_last - year_first + 1);
    for (int i = 0; i < n; i++){
        printf("%04d %02d %02d\n", dates[i].Year, dates[i].Month, dates[i].Day);
    }
    free(dates);
}
