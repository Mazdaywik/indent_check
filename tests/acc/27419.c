#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool areArraysEqual(int arr1[], int arr2[]) {
    for (int i = 0; i < 8; i++) {
        if (arr1[i] != arr2[i]) {
            return false;
        }
    }
    return true;
}

void generatePermutations(int arr[], int arr2[], int currentIndex) {
    if (currentIndex == 7) {
        if (areArraysEqual(arr, arr2)) {
            printf("yes\n");
            exit(0);
        }
    } else {
        for (int i = currentIndex; i < 8; i++) {
            int temp = arr[currentIndex];
            arr[currentIndex] = arr[i];
            arr[i] = temp;

            generatePermutations(arr, arr2, currentIndex + 1);

            temp = arr[currentIndex];
            arr[currentIndex] = arr[i];
            arr[i] = temp;
        }
    }
}

int main() {
    int arr1[8], arr2[8];
    for (int i = 0; i < 8; i++) {
        scanf("%d", &arr1[i]);
    }
    for (int i = 0; i < 8; i++) {
        scanf("%d", &arr2[i]);
    }

    generatePermutations(arr1, arr2, 0);

    printf("no\n");

    return 0;
}
