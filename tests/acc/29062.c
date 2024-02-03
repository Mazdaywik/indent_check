#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void revarray(void* base, size_t nel, size_t width) {

        void* temp = malloc(width);

        for (size_t i = nel / 2; i < nel; i++) {

            void* left = (char* )base + i * width;
            void* right = (char* )base + (nel - i - 1) * width;

            memcpy(temp, left, width);
            memcpy(left, right, width);
            memcpy(right, temp, width);
        }

        free(temp);

}