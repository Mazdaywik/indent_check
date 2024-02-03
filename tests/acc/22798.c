#include <stdio.h>

void swap(long *a, long *b){
    long t = *a;
    *a = *b;
    *b = t;
}

void selection_sort(long *arr, long low, long high){
    long i = low;

    while(i < high){
        long j = i + 1;

        while(j <= high){
            if(*(arr + j) < *(arr + i))
                swap(arr + i, arr + j);
            j++;
        }

        i++;
    }
}

long partition(long *arr, long low, long high){
    long i = low, j = low;
    while(j < high){
        if(*(arr + j) < *(arr + high)){
            swap(arr + i, arr + j);
            i++;
        }
        j++;
    }
    swap(arr + i, arr + high);
    return i;
}

void quick_sort(long *arr, long low, long high, long m){
    LABEL:
        if(low < high){
            if(high - low + 1 < m){
                selection_sort(arr, low, high);
            }
            else{
                long i = partition(arr, low, high);
                if(i - low < high - i){
                    quick_sort(arr, low, i - 1, m);
                    low = i + 1;
                }
                else {
                    quick_sort(arr, i + 1, high, m);
                    high = i - 1;
                }
                goto LABEL;
            }
        }
}

int main(void){
    long n, m;

    scanf("%ld %ld", &n, &m);

    long arr[n];

    for(long i = 0; i < n; i++)
        scanf("%ld", &arr[i]);

    quick_sort(arr, 0, n - 1, m);

    for(long i = 0; i < n; i++)
        printf("%ld ", arr[i]);

    return 0;
}