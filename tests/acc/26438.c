
#include <stdio.h>
#include <stdbool.h>

void bubblesort(unsigned long nel,
                int (*compare)(unsigned long, unsigned long),
                void (*swap)(unsigned long, unsigned long)) {

    if (nel<=1)
        return;
    bool swapped = true;
    unsigned long start = 0;
    unsigned long end = nel - 1;

    while (swapped) {
        swapped = false;

        for (unsigned long i = start; i < end; i++) {
            if (compare(i, i + 1) > 0) {
                swap(i, i + 1);
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
        swapped = false;

        end--;

        for (unsigned long i = end; i > start; i--) {
            if (compare(i - 1, i) > 0) {
                swap(i - 1, i);
                swapped = true;
            }
        }

        start++;
    }
}