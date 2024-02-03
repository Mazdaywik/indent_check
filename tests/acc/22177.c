#include <stdio.h>

void intersect(int A, int B) {
    int result = A & B;
    for (int i = 0; i < 32; i++) {
        if ((result >> i) & 1) {
            printf("%d ", i);
        }
    }
}

int main() {
    int sizeA, sizeB;
    int elemA = 0, elemB = 0;
    scanf("%d", &sizeA);
    for (int i = 0; i < sizeA; i++) {
        int elem;
        scanf("%d", &elem);
        elemA |= (1 << elem); 
        }

    scanf("%d", &sizeB);
    for (int i = 0; i < sizeB; i++) {
        int elem;
        scanf("%d", &elem);
        elemB |= (1 << elem);
    }

    intersect(elemA, elemB);

    return 0;
}