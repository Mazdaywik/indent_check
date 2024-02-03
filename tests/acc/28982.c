#include <stdio.h>

void intersectLoop(int setA, int setB) {
    int result = 0;

    for (int i = 0; i < 32; i++) {
        int mask = 1 << i;
        if ((setA & mask) && (setB & mask)) {
            result |= mask;
        }
    }

    for (int i = 0; i < 32; i++) {
        int mask = 1 << i;
        if (result & mask) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

int main() {
    int sizeA, sizeB;
    
    scanf("%d", &sizeA);
    int setA = 0;
    for (int i = 0; i < sizeA; i++) {
        int element;
        scanf("%d", &element);
        setA |= (1 << element);
    }
    scanf("%d", &sizeB);
    int setB = 0;
    for (int i = 0; i < sizeB; i++) {
        int element;
        scanf("%d", &element);
        setB |= (1 << element);
    }

    intersectLoop(setA, setB);

    return 0;
}
