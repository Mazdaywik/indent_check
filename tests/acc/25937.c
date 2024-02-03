#include <stdio.h>

void intersect() {
    int temp;
    int size_a; 
    int a = 0;
    scanf("%d", &size_a);
    for (int i = 0; i < size_a; i++) {
        scanf("%d", &temp);
        a |= (1 << temp);
    }
    
    int size_b; 
    int b = 0;
    scanf("%d", &size_b);
    for (int i = 0; i < size_b; i++) {
        scanf("%d", &temp);
        b |= (1 << temp);
    }

    int c = a & b;
    for (int i = 0; i < 32; i++) {
        if (c & (1 << i)) {
            printf("%d ", i);
        }
    }
}
int main() {
    intersect();
    return 0;
}
