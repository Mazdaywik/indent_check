#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Date {
    int Day, Month, Year;
} Date;

void countSort(Date *array, int size, int (*getVal)(Date), int range) {
    Date *output = malloc(size * sizeof(Date));
    int count[range + 1], i;

    memset(count, 0, sizeof(count));

    for (i = 0; i < size; i++) {
        count[getVal(array[i])]++;
    }

    for (i = 1; i <= range; i++) {
        count[i] += count[i - 1];
    }

    for (i = size - 1; i >= 0; i--) {
        output[count[getVal(array[i])] - 1] = array[i];
        count[getVal(array[i])]--;
    }

    for (i = 0; i < size; i++) {
        array[i] = output[i];
    }

    free(output);
}

int getDay(Date date) {
    return date.Day;
}

int getMonth(Date date) {
    return date.Month;
}

int getYear(Date date) {
    return date.Year - 1970; // Adjust year range to start from 0
}

void radixSortDates(Date *dates, int size) {
    countSort(dates, size, getDay, 31);   
    countSort(dates, size, getMonth, 12); 
    countSort(dates, size, getYear, 61);  
}

int main() {
    int size;
    scanf("%d", &size);
    Date *dates = (Date*) malloc(size * sizeof(Date));

    if (dates == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(1);
    }

    for (int i = 0; i < size; i++) {
        scanf("%d %d %d", &dates[i].Year, &dates[i].Month, &dates[i].Day);
    }

    radixSortDates(dates, size);

    for (int i = 0; i < size; i++) {
        printf("%04d %02d %02d\n", dates[i].Year, dates[i].Month, dates[i].Day);
    }

    free(dates);
    return 0;
}
