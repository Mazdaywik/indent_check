#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Date {
    int Day, Month, Year;
};

int key(int i, struct Date date){
    if(i == 2) return date.Day;
    if(i == 1) return date.Month;
    return date.Year;
}

void* DistributionSort(int typeofdate, struct Date *s, int n){
    int size_count = 0;
    if(typeofdate == 0) size_count = 2031;
    if(typeofdate == 1) size_count = 13;
    if(typeofdate == 2) size_count = 32;
    int *count = calloc(size_count, sizeof(int));
    int j = 0;
    while(j < n){
        int k = key(typeofdate, s[j]);
        count[k] += 1;
        j += 1;
    }
    int i = 1;
    while(i < size_count){
        count[i] = count[i] + count[i - 1];
        i += 1;
    }
    j = n - 1;
    struct Date *l = calloc(n, sizeof(struct Date));
    while(j >= 0){
        int k = key(typeofdate, s[j]);
        i = count[k] - 1;
        count[k] = i;
        l[i] = s[j];
        j -= 1;
    }
    free(count);
    free(s);
    return l;
}

void *RadixSort(int q, struct Date *s, int n){
    struct Date *d = s;
    int i = q - 1;
    while(i >= 0){
        d = DistributionSort(i, d, n);
        i -= 1;
    }
    return d;
}


int main(int args, char **argv){
    int n = 0;
    scanf("%d", &n);
    struct Date *dates = calloc(n, sizeof(struct Date));
    for(int i = 0; i < n; i++){
        struct Date date;
        int y, m, d = 0;
        scanf("%d %d %d", &y, &m, &d); 
        date.Day = d;
        date.Month = m;
        date.Year = y;
        dates[i] = date;
        
    }
    struct Date *dates_sorted = RadixSort(3, dates, n);
    for(int i = 0; i < n; i++){
        struct Date date = dates_sorted[i];
        printf("%04d %02d %02d \n", date.Year, date.Month, date.Day);
    }
    free(dates_sorted);
    // printf("%04d %02d %02d", y, m ,d);
    return 0;
}