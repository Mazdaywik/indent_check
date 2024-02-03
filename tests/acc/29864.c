#include <stdio.h>

int main() {
    unsigned int A = 0, B = 0, intersection;
    int n, element, i;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &element);
        A |= 1 << element;
    }
    
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &element);
        B |= 1 << element;
    }
    
    intersection = A & B;
    
    for (i = 0; i < 32; i++) {
        if (intersection & (1 << i)) {
            printf("%d ", i);
        }
    }
    
    printf("\n");
    return 0;
}