unsigned long peak(unsigned long nel,
                   int (*less)(unsigned long i, unsigned long j))
{
    for(unsigned long ind = 1; ind < nel - 1; ind++){
        if(!less(ind, ind - 1) && !less(ind, ind + 1)){
            return ind;
        }
    }
    return (nel == 1 || !less(0, 1)) ? 0 : nel - 1;
}