void bubblesort(unsigned long nel, int (*compare)(unsigned long i, unsigned long j),
                void (*swap)(unsigned long i, unsigned long j)) {
    if (!nel)
        return;
    unsigned long start = 0, control = nel-1;
    unsigned long end = control;
    while (start < end) {
        for (unsigned long i = start; i < end; i++) {
            if (compare(i, i + 1) == 1) {
                swap(i, i + 1);
                control = i;
            }
        }
        end = control;
        for (unsigned long i = end; i > start; i--) {
            if (compare(i, i - 1) == -1) {
                swap(i, i - 1);
                control = i;
            }
        }
        start = control;

    }
}