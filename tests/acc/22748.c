#include <stdio.h>
#include <stdlib.h>


void swap(long *a, long *b){
    long t = *a;
    *a = *b;
    *b = t;
}

int compare(const long *a, const long *b){
    long n1 = *a, n2 = *b;

    if(n1 < 0)
        n1 = -n1;
    if(n2 < 0)
        n2 = -n2;
    
    return (n1 - n2);  
}

void mearge(long *arr, long low, long middle, long high){
    long arr3[high - low + 1];
    long index_arr1 = low, index_arr2 = middle + 1, index_arr3 = 0;

    while(index_arr1 < middle + 1 && index_arr2 <= high){
        if(compare(arr + index_arr1, arr + index_arr2) <= 0){
            arr3[index_arr3] = *(arr + index_arr1);
            index_arr1++;
            index_arr3++;
        }
        else {
            arr3[index_arr3] = *(arr + index_arr2);
            index_arr2++;
            index_arr3++;
        }
    }

    while(index_arr1 < middle + 1){
        arr3[index_arr3] = *(arr + index_arr1);
        index_arr1++;
        index_arr3++;
    }

    while(index_arr2 <= high){
        arr3[index_arr3] = *(arr + index_arr2);
        index_arr2++;
        index_arr3++;
    }

    long j = 0;
    for(long i = low; i <= high; i++){
        *(arr + i) = arr3[j];
        j++;
    }
}

void insertion_sort(long *arr, long low, long high){
    long i = low;
    while(i <= high){
        long elem = i;
        long loc = i - 1;

        while(loc >= low && compare(arr + loc, arr + elem) > 0){
            swap(arr + elem, arr + loc);
            elem = loc;
            loc--;
        }
        
        i++;
    }
}

void mearge_sort(long *arr, long low, long high){
    if(low < high){
        if(high - low <= 4)
            insertion_sort(arr, low, high);

        else {
            long middle = (low + high) / 2;

            mearge_sort(arr, low, middle);
            mearge_sort(arr, middle + 1, high);
            mearge(arr, low, middle, high);
        }
    }
}

int main(void){ 
    long n;
    scanf("%ld", &n);

    long arr[n];

    for(long i = 0; i < n; i++)
        scanf("%ld", &arr[i]);
    
    mearge_sort(arr, 0, n - 1);

    for(int i = 0; i < n; i++)
        printf("%ld ", arr[i]);
    
    return 0;
}