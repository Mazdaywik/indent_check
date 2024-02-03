void bubblesort(unsigned long nel,
                int (*compare)(unsigned long i, unsigned long j),
                void (*swap)(unsigned long i, unsigned long j)) {
    if(nel == 0){
        return;
    }
    unsigned long left = 0;
    unsigned long right = nel - 1;
    int route = 0;

    while (left < right) {
        if (route == 0) {
            for (unsigned long i = left; i < right; i++) {
                if (compare(i, i + 1) == 1) {
                    swap(i, i + 1);
                }
            }
            right--;
            route = 1;
        } else {
            for (unsigned long i = right; i > left; i--) {
                if (compare(i - 1, i) == 1) {
                    swap(i - 1, i);
                }
            }
            left++;
            route = 0;
        }
    }
}