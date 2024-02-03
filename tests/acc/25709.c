void bubblesort(unsigned long nel,
        int (*compare)(unsigned long i, unsigned long j),
        void (*swap)(unsigned long i, unsigned long j))
{
    for (unsigned long step = 0; step < (nel / 2); ++step) {
        for (unsigned long i = step; i < nel - step - 1; ++i) {
            if (compare(i, i + 1) == 1) {
                swap(i, i + 1);
                }
            }
        for (unsigned long i = nel - step - 2; i > step; --i) {
            if (compare(i, i - 1) == -1) {
                swap(i, i - 1);
                }
        }
    }
}