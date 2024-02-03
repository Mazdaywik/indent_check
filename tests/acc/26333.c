typedef unsigned long lu;

void bubblesort(lu nel, 
    int (*compare)(lu i, lu j), 
    void (*swap)(lu i, lu j)) {

    lu left = 0;
    lu right = nel - 1;

    if (nel == 1 || nel == 0) return;

    while (left <= right) {
        for (lu i = right; i > left; i--) {
            if (compare(i, i - 1) < 0) {
                swap(i, i - 1);
            }
        }
        ++left;
        for (lu i = left; i < right; i++) {
            if (compare(i, i + 1) > 0) {
                swap(i, i + 1);
            }
        }
        --right;
    }
}