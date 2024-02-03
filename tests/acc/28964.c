#include <stdio.h>

int array[8] = {1, 3, 4, 7, 8, 6, 4, 2}; 

int less(unsigned long i, unsigned long j) {
    return array[i] < array[j];
}

unsigned long peak(unsigned long nel, int (*less)(unsigned long, unsigned long)) {
    unsigned long a = 0, b = nel - 1;
    while (a <= b) {
        unsigned long c = (a + b) / 2;

        if (c > 0 && less(c, c - 1)) {
            b = c - 1;
        } else if (c < nel - 1 && less(c, c + 1)) {
            a = c + 1;
        } else {
            return c; 
        }
    }
    return -1;
}

int main() {
    unsigned long peakIndex = peak(8, less);
    if ((peakIndex == 0 || !less(peakIndex, peakIndex - 1)) &&
        (peakIndex == 7 || !less(peakIndex, peakIndex + 1))) {
        printf("correct\n");
    } else {
        printf("incorrect\n");
    }
    return 0;
}