    #include <stdio.h>

    void revarray(void *base, size_t nel, size_t width)
    {
        char *first = (char *)base;
        char *last = first + (nel - 1) * width;
        while (first < last){
            for (size_t i = width; i > 0; i--){
                char change = first[width - i];
                first[width - i] = last[width - i];
                last[width - i] = change;
            }
            first += width;   
            last -= width;
        }
    }