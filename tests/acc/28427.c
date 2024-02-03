#include <stdio.h>

void intersection(int setA, int setB) {
    int result = setA & setB;

    int firstElementPrinted = 0;
    for (int i = 0; i < 32; i++) {
        if ((result & (1 << i)) != 0) {
            if (firstElementPrinted) {
            }
            printf("%d ", i);
            firstElementPrinted = 1;
        }
    }
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

    intersection(setA, setB);

    return 0;
}