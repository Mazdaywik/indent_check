#include <stdio.h>

int isElementInSet(int set, int element) {
    return (set & (1 << element)) != 0;
}

int intersection(int setA, int setB) {
    return setA & setB;
}

int main() {
    int sizeA, sizeB;

    scanf("%d", &sizeA);
    
    int setA = 0;
    for (int i = 0; i < sizeA; ++i) {
        int element;
        scanf("%d", &element);
        setA |= (1 << element);
    }

    scanf("%d", &sizeB);

    int setB = 0;
    for (int i = 0; i < sizeB; ++i) {
        int element;
        scanf("%d", &element);
        setB |= (1 << element); 
    }

    int result = intersection(setA, setB);


    for (int i = 0; i < 32; ++i) {
        if (isElementInSet(result, i)) {
            printf("%d ", i);
        }
    }

    return 0;
}