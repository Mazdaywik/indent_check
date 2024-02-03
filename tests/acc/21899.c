unsigned long peak(unsigned long nel, int (*less)(unsigned long i, unsigned long j)){ 
    if (nel == 1){
        return 0;
    }
    if (less(1, 0)){
        return 0;
    }
    if (less(nel - 2, nel - 1)){
        return nel - 1;
    }
    for (int i = 1; i < nel - 1; i++){
        if ((less(i, i - 1) == 0) && (less(i, i + 1) == 0)){
            return i;
        } 
    }
   return 0;
}