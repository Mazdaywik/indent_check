unsigned long peak(unsigned long nel, int (*less)(unsigned long i, unsigned long j)) {
    if (nel == 1) {
        return 0;
    }
    if (!less (0, 1)) {
        return 0;
    }
    if (!less (nel-1, nel-2)) {
        return (nel-1);
    }
    for (unsigned long i = 1; i < (nel-1); i++) {
        if (!less (i, i-1) && !less (i, i+1)) {
            return i;
        }
    }
}