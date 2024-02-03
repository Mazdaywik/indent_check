#include <stdio.h>
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <wchar.h>

#define min(a,b) ((a) < (b) ? (a) : (b))
//#define max(a, b) ((a) < (b) ? (b) : (a))
#define maxsz (int)1e6 + 1000
#define inf (int)1e9

int maxx(int x, int y){
    return x < y ? y : x;
}

struct Date {
    int Day, Month, Year;
};

int keys[3] = {31, 12, 61};

int get_raz(struct Date date, int base){
    if (base == 0) {
        return date.Day - 1;
    } else if (base == 1) {
        return date.Month - 1;
    } else {
        return date.Year - 1970;
    }
}

void datesort(struct Date *dates, int n, int base){
    int key = keys[base];
    int *a = (int*) malloc((key + 1) * sizeof(int));
    for (int i = 0; i < key; ++i){
        a[i] = 0;
    }
    for (int i = 0; i < n; ++i){
        int k = get_raz(dates[i], base);
        a[k] += 1;
    }
    for (int i = 1; i < key; ++i){
        a[i] += a[i - 1];
    }
    struct Date dates2[n];
    for (int i = n - 1; i >= 0; --i){
        int index = get_raz(dates[i], base);
        if (a[index] - 1 < 0){
            continue;
        }
        dates2[a[index] - 1] = dates[i];
        a[index] -= 1;
    }
    for (int i = 0; i < n; ++i){
        dates[i] = dates2[i];
    }
    free(a);
}

int main(){
    int n;
    scanf("%d", &n);
    struct Date dates[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d %d %d", &dates[i].Year, &dates[i].Month, &dates[i].Day);
    }
    for (int i = 0; i < 3; ++i) {
        datesort(dates, n, i);
    }
    for (int i = 0; i < n; ++i) {
        printf("%04d %02d %02d\n", dates[i].Year, dates[i].Month, dates[i].Day);
    }
    return 0;
}