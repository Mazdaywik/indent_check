#include <stdio.h>

unsigned long ARRAY_SIZE = 10;
int array[10];

void swap(unsigned long i, unsigned long j) {
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

int compare(unsigned long i, unsigned long j) {
    if (array[i] < array[j])
        return -1;
    else if (array[i] > array[j])
        return 1;
    else
        return 0;
}

void bubblesort(unsigned long nel, 
        int (*compare)(unsigned long i, unsigned long j), 
        void (*swap)(unsigned long i, unsigned long j)) {
    if (nel == 0) return;

    unsigned long l = 0, r = nel - 1;

    while (l < r) {
        unsigned long new_r = l, new_l = r;
        for (unsigned long i = l; i < r; i++) { 
            if (compare(i, i + 1) > 0) {
                swap(i, i + 1);
                new_r = i;
            }
        }
        r = new_r;

        for (unsigned long i = r; i > l; i--) {
            if (compare(i - 1, i) > 0) {
                swap(i - 1, i);
                new_l = i;
            }
        }
        l = new_l;
    }
}

void printArray() {
    for (unsigned long i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void testBubblesort() {
    ARRAY_SIZE = 10;
    int tempArray[10] = {10, 3, 5, 7, 2, 8, 1, 9, 6, 4};
    for (unsigned long i = 0; i < ARRAY_SIZE; i++) {
        array[i] = tempArray[i];
    }

    printArray();

    bubblesort(ARRAY_SIZE, compare, swap);

    printArray();
}

int main() {
    testBubblesort();
    return 0;
}
