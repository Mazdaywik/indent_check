unsigned long binsearch(unsigned long nel, int (*compare)(unsigned long i))
{
    unsigned long left = 0, right = nel - 1, mid = (left + right) / 2;
    while (left <= right) {
        int result = compare(mid);
        if (result== 0) {
            return mid;
        }
        else if (result == -1) {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
        mid = (left + right) / 2;
    }
    return nel;
}