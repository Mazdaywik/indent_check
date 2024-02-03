#include <stdio.h>

void bubblesort(unsigned long nel,
        int (*compare)(unsigned long i, unsigned long j),
                void (*swap)(unsigned long i, unsigned long j)) {
    if (nel <= 1) return;
    unsigned long left = 0;
    unsigned long right = nel - 1;
    for (unsigned long i = 0; i < nel - 1; i++) {
        if (i % 2 == 1) {
            for (unsigned long j = left; j < right; j++) {
                if (compare(j, j + 1) == 1) {
                    swap(j, j + 1);
                }
            }
            right--;
        } else {
            for (unsigned long j = right; j > left; j--) {
                if (compare(j, j - 1) == -1) {
                    swap(j, j - 1);
                }
            }
            left++;
        }
    }
}