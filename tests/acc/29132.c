#include<stdio.h>
#include<stdlib.h>

void insertion_sort(int* arr, int n, int start){
        int i = start + 1, elem, loc;
        n += start;
        while(i < n){
                elem = arr[i];
                loc = i - 1;
                while((loc >= start) && (abs(arr[loc]) > abs(elem))){
                        arr[loc + 1] = arr[loc];
                        loc--;
                }
                arr[loc + 1] = elem;
                i++;
        }
}
void merge(int* arr, int k, int l, int m){
        int t[m - k + 1];
        int i = k, j = l + 1, h = 0;
        while(h < m - k + 1){
                if((j <= m) && ((i == l + 1) || (abs(arr[j]) < abs(arr[i])))){
                        t[h] = arr[j];
                        j++;
                }
                else{
                        t[h] = arr[i];
                        i++;
                }
        h++;
        }

        for(i = k, h = 0; i < m + 1;i++, h++){

        arr[i] = t[h];
        }
}
void mergesortrec(int* arr, int low, int high){
        if(low + 4 < high){
                int med = (low + high) / 2;
                mergesortrec(arr, low, med);
                mergesortrec(arr, med + 1, high);

                merge(arr, low, med, high);
        }
        else{
                insertion_sort(arr, high - low + 1, low);
        }
}
void mergesort(int* arr, int n){
        //xz
        mergesortrec(arr, 0, n - 1);
}


int main(){
        int i, size;
        scanf("%d", &size);
        int arr[size];
        for(i = 0; i < size; i++) scanf("%d", &arr[i]);

        mergesort(arr, size);
        for(i = 0; i < size; i++) printf("%d ", arr[i]);

        return 0;
}