#include <stdio.h>

typedef unsigned long ul;

ul binsearch(ul nel, int (*compare)(ul i)) {
    
    ul left = 0;
    ul right = nel - 1;

    while (left <= right) {

        ul middle = (left + right) / 2;

        if (compare(middle) == 0) return middle;
        else if (compare(middle) == 1) right = middle - 1;
        else left = middle + 1;

    }
    return nel;
}