void bubblesort(unsigned long nel,
        int (*compare)(unsigned long i, unsigned long j),
        void (*swap)(unsigned long i, unsigned long j))
{
    if (nel > 1) {
        unsigned long head = 0;
        unsigned long tail = nel-1;
        char beenSorted;
        while (head < tail) {
            beenSorted = 0;
            for (unsigned long i = head; i < tail; ++i) {
                if (compare(i, i+1) > 0) {  
                    swap(i, i+1);
                    beenSorted = 1;
                }
            }
            if (!beenSorted) {
                break;
            }
            beenSorted = 0;
            for (unsigned long i = tail-1; i > head; --i) {
                if (compare(i, i-1) < 0) {
                    swap(i, i-1);
                    beenSorted = 1;
                }
            }
            if (!beenSorted) {
                break;
            }

            ++head;
            --tail;
        }
    }
}