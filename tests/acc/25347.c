void swap(int *a, int *b) {
    int c = *a;
    *a = *b;
    *b = c;
}

int compare(unsigned long i, unsigned long j) {
    if (i < j) return -1;
    else if (i > j) return 1;
    else return 0;
}

void bubblesort(unsigned long nel,
        int (*compare)(unsigned long i, unsigned long j),
        void (*swap)(unsigned long i, unsigned long j)) {
    if (!nel) {
        return;
    }
    unsigned long low = 0;
    unsigned long high = nel - 1;
    for (unsigned long i = 0; i < nel - 1; i++) {
        if (i % 2 == 0) {
            for (unsigned long j = low; j < high; j++) {
                if (compare(j, j + 1) > 0) {
                    swap(j, j + 1);
                }
            }
            high--;
        } else {
            for (unsigned long j = high; j > low; j--) {
                if (compare(j - 1, j) > 0) {
                    swap(j - 1, j);
                }
            }
            low++;
        }
    }
}