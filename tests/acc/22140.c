#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

void insertsort(int i, int nel, int a[]){
    int loc, el, j;
    j = i + 1;
    while (j < nel + 1){
        el = a[j];
        loc = j - 1;
        while ((loc >= i) && abs(a[loc]) > abs(el)){
            a[loc + 1] = a[loc];
            loc -= 1;
        }
        a[loc + 1] = el;
        j += 1;
    }

}
void merge(int left, int med, int right, int a[]){
    int i = left, j = med + 1, h = 0;
    int b[right - left + 1];
    while (h < right - left + 1){
        if (j <= right && ((i == med + 1) || abs(a[i]) > abs(a[j]))){
            b[h] = a[j];
            j += 1;
        }
        else{
            b[h] = a[i];
            i += 1;
        }
        h += 1;
    }
    for (int i = 0; i < h; i++){
        a[left + i] = b[i];
    }    
}
void mergesort(int left, int right, int a[]){
    int med = 0;
    if (right - left + 1 < 5){
        insertsort(left, right, a);
    }
    else{
        if (left < right) med = (left + right) / 2;
        mergesort(left, med, a);
        mergesort(med + 1, right, a);
        merge(left, med, right, a);
    }
}
int main(){
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    mergesort(0, n - 1, a);
    for (int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
}