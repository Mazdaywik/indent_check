#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, summa = 0, right, left, max_summa, k;
    scanf("%d", &n);
    int *mas = (int*)malloc(n * sizeof(int));
    for (int i=0; i<n; i++) {
        scanf("%d", &mas[i]);
    }
    scanf("%d", &k);
    right = k;
    left = 0;
    for (int i=0; i<n; i++) {
        if (i<k) {
            summa += mas[i];
        }
    }
    max_summa = summa;
    while (right < n) {
        summa += mas[right];
        summa -= mas[left];
        right += 1;
        left += 1;
        if (summa > max_summa) {
            max_summa = summa;
        }
    }
    printf("%d", max_summa);
    free(mas);
    return 0;
}