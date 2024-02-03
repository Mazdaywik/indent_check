unsigned long peak(unsigned long nel, int (*less)(unsigned long i, unsigned long j)){
    for(unsigned long i = 1; i < nel - 1; i++){
        if(less(i, i - 1) == 0 && less(i, i + 1) == 0)
            return i;
    }
}