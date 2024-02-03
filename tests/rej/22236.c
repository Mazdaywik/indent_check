#include <stdio.h>

int mas[] = {45,543,54345,54,45,43,34,5,34534,5,345,34,5,345};
int n = sizeof(mas) / sizeof(mas[0]);
int compare(unsigned long i, unsigned long j) {
    if (mas[i] > mas[j]) 
        return 1;
    if (mas[i] < mas[j])
        return -1;
    if (mas[i] == mas[j])
        return 0;
}

void swap(unsigned long i, unsigned long j){
    int hold;
    hold = mas[i];
    mas[i] = mas[j];
    mas[j] = hold;
}

void bubblesort(unsigned long nel,
                int (*compare)(unsigned long i, unsigned long j),
                void (*swap)(unsigned long i, unsigned long j)){
                    if(nel == 0)
                    return;
    for (unsigned long j = 0; j < nel - 1; j++) {
        if (j % 2 == 0) {
            for (unsigned long i = 0; i < nel - 1; i++) {
                if (compare(i, i + 1) > 0) {
                    swap(i, i + 1);
                }
            }
        } else {
            for (unsigned long i = nel - 1; i > 0; i--) {
                if (compare(i - 1, i) > 0) {
                    swap(i - 1, i);
                }
            }
        }  
    }
}

int main() {
    bubblesort(n, compare, swap);
    for (int i = 0; i < n; ++i) {
        printf("%d ", mas[i]);
    }
    return 0;
}