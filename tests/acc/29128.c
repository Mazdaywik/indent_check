#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int maxarray(void* base, size_t nel, size_t width, 
        int (*compare)(void* a, void* b)) {

    for (int i = 0; i < nel; i++) {

        void* currElem = (void*)((char*)base + i * width);
        bool isMax = true;

        for (int j = i + 1; j < nel; j++) {
            
            void* secondElem = (void*)((char*)base + j * width);
            
            if (compare(currElem, secondElem) <= 0) {
                isMax = false;
                break;
            }
        }

        if (isMax) return i;

    }
}