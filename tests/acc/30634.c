#include<stdio.h>
#include<stdlib.h>
struct Task{
    int low, high;
};

void quick_sort(int *array, long len){
    struct Task t = {0, len};
    struct Task stack[20000];
    stack[0] = t;
    int esp = 0; // Регистр стека как в ассемблере, но без адресной базы.
    int* temp_lo = (int *)calloc(len, sizeof(int));
    int* temp_hi = (int *)calloc(len, sizeof(int));
    while (esp != -1){
        t = stack[esp];
        esp--;
        if (t.high > t.low + 1){
            int ind_lo = 0, ind_hi = 0;
            int elem = array[t.low], count = 0;
            for (int i = 0; i < t.high - t.low; i++){
                if (array[t.low + i] < elem){
                    temp_lo[ind_lo] = array[t.low + i];
                    ind_lo++;
                }
                else if (array[t.low + i] == elem){
                    count++;
                }
                else {
                    temp_hi[ind_hi] = array[t.low + i];
                    ind_hi++;
                }
            }
            for (int i = 0; i < ind_lo; i++){
                array[t.low + i] = temp_lo[i];
            }
            for (int i = 0; i < count; i++){
                array[t.low + ind_lo + i] = elem;
            }
            for (int i = 0; i < ind_hi; i++){
                array[t.low + ind_lo + count + i] = temp_hi[i];
            }
            esp++;
            struct Task t1 = {t.low, t.low + ind_lo};
            stack[esp] = t1;
            esp++;
            t1.low = t.high - ind_hi;
            t1.high = t.high;
            stack[esp] = t1;
        }
    }
    free(temp_lo);
    free(temp_hi);
}

int main(){
    long n = 0;
    scanf("%ld", &n);
    int *nums = (int *)malloc(n * sizeof(int));
    for (long i = 0; i < n; i++){
        scanf("%d", nums + i);
    }
    quick_sort(nums, n);
    for (long i = 0; i < n; i++){
        printf("%d\n", nums[i]);
    }
    free(nums);
}