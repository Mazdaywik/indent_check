#include <stdio.h>
#include <inttypes.h>
#include <math.h>

uint32_t to_numeric(int size) {
    
    uint32_t result = 0;

    for (int i = 0; i < size; i++) {
        int number;
        scanf("%d", &number);
        uint32_t curr = (uint32_t)pow(2, number);
        result += curr;
    }

    return result;

}

int main(int argc, char **argv) {

    int size_A, size_B;

    scanf("%d", &size_A);
    if (size_A == 0) return 0;
    uint32_t numA = to_numeric(size_A);
    
    scanf("%d", &size_B);
    if (size_B == 0) return 0;
    uint32_t numB = to_numeric(size_B);

    uint32_t unionAB = numA & numB;

    for (int i = 0; i < 32; i++) {

        int base_two = pow(2, i);

        int in_union = base_two & unionAB;

        if (in_union) printf("%d ", i);

    }

    return 0;

}