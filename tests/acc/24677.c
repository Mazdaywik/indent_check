unsigned long peak(unsigned long nel, int (*less)(unsigned long i, unsigned long j)){
    if (nel == 1){
            return 0;
        }
    for (unsigned long i = 0; i < nel; i++){
        if ((i == 0) && !less(0, 1)) {
            return i;
        }
        else if ((i == nel-1) && !less(i, i-1)) {
            return i;
        }
        else if ((i != 0) && (i != nel-1) && !less(i, i-1) && !less(i, i+1)) {
            return i;
        }
    }
}