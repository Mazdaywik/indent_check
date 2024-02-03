#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b) {
    int copy_a = *a;
    *a = *b;
    *b = copy_a;
}

int arraysEqual(int* A, int* B, int size) {
    for (int i = 0; i < size; i++) {
        if (A[i] != B[i]) {
            return 0;
        }
    }
    return 1;
}

void generate_permut(int* A, int size, int index, int* B, int sizeB, int* found) {
    if (index == size) {
        if (arraysEqual(A, B, sizeB)) {
            *found = 1;
        }
    } else {
        for (int i = index; i < size; i++) {
            swap(&A[index], &A[i]);
            generate_permut(A, size, index + 1, B, sizeB, found);
            swap(&A[index], &A[i]);
        }
    }
}

int is_permut(int* A, int sizeA, int* B, int sizeB) {
    int found = 0;
    generate_permut(A, sizeA, 0, B, sizeB, &found);
    return found;
}

int main(){
    int len = 8;
    int A[len], B[len];
    for (int i = 0; i < len; i++) {
        scanf ("%d", &A[i]);
    }
    for (int i = 0; i < len; i++) {
        scanf ("%d", &B[i]);
    }
    is_permut(A, len, B, len) == 1? printf("yes") : printf("no");
    
    return 0;
}