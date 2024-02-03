void bubblesort(unsigned long nel, int (*compare)(unsigned long i, unsigned long j), void (*swap)(unsigned long i, unsigned long j))
{
    if (nel <= 1) return;
    int swapped = 1;
    unsigned long left = 0, right = nel - 1;
    while (swapped) {
        swapped = 0;
        for (unsigned long i = left; i < right; i++) {
            if (compare(i, i + 1) == 1) {
                swap(i, i + 1);
                swapped = 1;
            }
        }
        right--;
        if (!swapped) break;
        for (unsigned long i = right; i > left; i--) {
            if (i >= nel || i - 1 >= nel) continue;
            if (compare(i, i - 1) == -1) {
                swap(i, i - 1);
                swapped = 1;
            }
        }
        left++;
    }
}