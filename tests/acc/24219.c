#include <stdio.h>

int count_el(int el, int array []) {
    int count = 0;
    for (int i = 0; i < 8; i++) {
        if (array[i] == el) count += 1;
    }
    return count;
}

int contains(int el, int array [][2]) {
    for (int i = 0; i < 8; i++) {
        if (el == array[i][0]) return i;
    }
    return -1;
}

int main(int argc, char **argv) {

    int arr_A[8], arr_B[8];

    for (int i = 0; i < 8; i++) scanf("%d", &arr_A[i]);
    for (int j = 0; j < 8; j++) scanf("%d", &arr_B[j]);

    int count_el_A[8][2] = { 0 };
    
    for (int i = 0; i < 8; i++) {
        if (arr_A[i] == 0) 
            count_el_A[i][1] = count_el(0, arr_A);
        if (contains(arr_A[i], count_el_A) != -1) 
            continue;
        else {
            count_el_A[i][0] = arr_A[i];
            count_el_A[i][1] = count_el(arr_A[i], arr_A); 
        }
    }

    for (int i = 0; i < 9; i++) {
        if (i == 8) {
            printf("yes");
            break;
        }
        int count = count_el(arr_B[i], arr_B);
        int index = contains(arr_B[i], count_el_A);
        if (index != -1) {
            if (count != count_el_A[index][1]) {
                printf("no");
                break;
            }
        }
        else { 
            printf("no"); break; 
        }
    }

    return 0;

}