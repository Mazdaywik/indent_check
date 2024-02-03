#include <stdio.h>

int main(void){
    unsigned int setA = 0;
    unsigned int setB = 0;
    int n;
    int element;

    // Чтение размера и элементов множества A
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &element);
        setA |= (1 << element);
    }

    // Чтение размера и элементов множества B
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &element);
        setB |= (1 << element);
    }

    // Вычисление пересечения множеств A и B
    unsigned int intersection = setA & setB;

    // Вывод отсортированных элементов пересечения
    for (int i = 0; i < 32; i++) {
        if ((intersection >> i) & 1) {
            printf("%d ", i);
        }
    }

    return 0;
}