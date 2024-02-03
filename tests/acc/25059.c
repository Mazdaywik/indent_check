#include<stdio.h>

void selectsort(int* arr, int start, int end){
        int j = end, k, i, t;
                while(j > start){
                        k = j;
                        i = j - 1;
                        while(i >= start){
                                if(arr[k] < arr[i]) k = i;
                                i = i - 1;
                        }
                        t = arr[j];
                        arr[j] = arr[k];
                        arr[k] = t;
                        j--;
                }
}

int partition(int* arr, int low, int high){
        int i = low, j = low, t;
        while(j < high){
                if(arr[j] < arr[high]){
                        t = arr[i];
                        arr[i] = arr[j];
                        arr[j] = t;
                        i++;
                }
                j++;
        }
        t = arr[i];
        arr[i] = arr[high];
        arr[high] = t;
        return i;
}

void quicksortrec(int* arr, int low, int high, int m){
        int q;

  //      printf("%d %d %d\n", low, high, m);

        if(high > low + m){
//              printf("%d %d %d\n", low, high, m);

                q = partition(arr, low, high);
                quicksortrec(arr, low, q - 1, m);
                quicksortrec(arr, q + 1, high, m);
        }
        else{

//              printf("%d %d\n", low, high);
                selectsort(arr, low, high);
        }
}
 
void quicksort(int* arr, int n, int m){
        quicksortrec(arr, 0, n - 1, m);
}
 

int main(){
        int i, size, m;
        scanf("%d%d", &size, &m);
        int arr[size];
        for(i = 0; i < size; i++) scanf("%d", &arr[i]);

        quicksort(arr, size, m);
        for(i = 0; i < size; i++) printf("%d ", arr[i]);

        return 0;
}