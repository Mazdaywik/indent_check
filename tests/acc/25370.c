#include <stdio.h>

typedef unsigned long lu;

lu peak(lu nel, int (*less)(lu i, lu j)) {

    if (nel == 1) return 0;
    lu right = nel - 1;
    if (less(right - 1, right)) return right;

    while (right >= 2) {

        lu middle = right - 1;
        lu left = middle - 1;

        if (!less(middle, right) && !less(middle, left)) return middle;
        else right -= 1;

    }
    return less(1, 0);
}