unsigned long binsearch(unsigned long nel, int (*compare)(unsigned long i)) {
    unsigned long left_half = 0;
    unsigned long right_half = nel - 1;
    
    while (left_half <= right_half) {
        unsigned long center = (left_half + right_half) / 2;
        int result = compare(center);
        
        switch (result)
        {
        case 0:
            return center;
            break;
        case -1:
            left_half = center + 1;
            break;
        case 1:
            right_half = center - 1;
            break;
        }
    }
    return nel;
}