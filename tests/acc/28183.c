void bubblesort(unsigned long nel,
                int (*compare)(unsigned long i, unsigned long j),
                void (*swap)(unsigned long i, unsigned long j)) {
    int swapped;

    if (nel < 2) {
        return;
    }

    for (unsigned long i = 0; i < nel - 1; ++i) {
        swapped = 0;

        for (unsigned long j = 0; j < nel - i - 1; ++j) {
            if (compare(j, j + 1) > 0) {
                swap(j, j + 1);
                swapped = 1;
            }
        }

        for (unsigned long j = nel - i - 2; j > i; --j) {
            if (compare(j - 1, j) > 0) {
                swap(j - 1, j);
                swapped = 1;
            }
        }

        if (!swapped) {
            break;
        }
    }
}