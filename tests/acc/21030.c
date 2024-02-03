unsigned long binsearch(unsigned long nel, int (*compare)(unsigned long i)){
    unsigned long indLeft = 0, indRight = nel - 1;
    while (indLeft <= indRight){
        unsigned long mid = (indLeft + indRight)/2;
        if (compare(mid) == 0){
            return mid;
        }
        if(compare(mid) == 1){
            indRight = mid - 1;
        }else{
            indLeft = mid + 1;
        }
    }
    return nel;
}