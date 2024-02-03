void bubblesort(unsigned long nel,
        int (*compare)(unsigned long i, unsigned long j),
        void (*swap)(unsigned long i, unsigned long j))
{
    unsigned long i, l = 0, r = nel - 1, move = 1;
    if (nel <= 1) return;
    while ((r > l) && (move == 1)) {
        move = 0;
        for (i = l; i < r; i++) {
            if (compare(i, i + 1) == 1) {
                swap(i, i + 1);
                move = 1;
            }
        }
        r--;
        for (i = r; i > l; i--) {
            if (compare(i, i - 1) == -1) {
                swap(i, i - 1);
                move = 1;
            }
        }
        l++;
    }
}