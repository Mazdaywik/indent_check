unsigned long peak(unsigned long nel,
    int (*less)(unsigned long i, unsigned long j))
{
    for (int i = 0; i < nel; ++i) {
        int r = i < nel - 1 && less(i, i + 1), l = i>0 && less(i, i - 1);
        if (r == 0 && l == 0) {
            return i;
        }
        
    }
}
