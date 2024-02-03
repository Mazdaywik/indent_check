#include<stdio.h>

union Int32 {
    int x;
    unsigned char bytes[4];
};

void DistributionSort(int key, int m, union Int32* s, int n){
        int count[m];
        for(int i = 0;i < m;i++)count[i] = 0;
        int j = 0, k;
        while(j < n){
                k = (s[j].x >= 0) ? s[j].bytes[key] + 256 : s[j].bytes[key];
                count[k]++;
                j++;
        }
        int i = 1;
        while(i < m){
                count[i] += count[i - 1];
                i++;
        }
        union Int32 d[n];
        j = n - 1;
        while(j >= 0){
                k = (s[j].x >= 0) ? s[j].bytes[key] + 256 : s[j].bytes[key];
                i = count[k] - 1;
                count[k] = i;
                d[i] = s[j];
                j--;
        }
//        for(i = 0; i < n; i++) printf("%d  %d  |  ", d[i].x, d[i].bytes[key]);
  //      printf("    \n");

        for(i = 0; i < n;i++) s[i] = d[i];
}

void RadixSort(int q, int m, union Int32* s, int n){
//      union Int32 d[n];
//      for(int i = 0;i < n;i++) d[i] = s[i];
        int i = 0;
        while(i <= q - 1){
                DistributionSort(i, m, s, n);
                i++;
        }
}


int main(){
        int size, i;
        scanf("%d", &size);
        union Int32 arr[size];
        for(i = 0; i < size; i++) scanf("%d", &arr[i].x);
        RadixSort(4, 512, arr, size);
        for(i = 0; i < size; i++) printf("%d  ", arr[i].x);

        return 0;
}