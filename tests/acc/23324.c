#include <stdio.h>
void swap(int a[], unsigned long i, unsigned long j) 
{
	int t = a[i];
	a[i] = a[j];
	a[j] = t;
}

void selectSort(int *a, int n)
{
    int min; 
    for (int i = 0; i < n - 1; i++) {
        min = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[min]) min = j;       
        }
        swap(a, i, min);
    }
}

int partition(int a[], int left, int right)
{
    int i= left, j=left;
    while (j < right){
        if(a[j] < a[right]){
            swap(a, i, j);
            i += 1;
        }
        j += 1;
    }
    swap(a, i, right);
    return i;
}

void quicksort(int a[], int left, int right, int n, int m){
    if(right - left + 1 < m) selectSort(a, right - left + 1);
    while(left < right){
        int q = partition(a, left, right);
        if(q-left < right - q){
            quicksort(a, left, q-1, n, m);
            left = q+1;
        }
        else{
            quicksort(a, q+1, right, n, m);
            right = q-1;
        }
    }
}

int main(int argc, char** argv)
{
    int n, m;
    scanf("%d%d", &n, &m);
    int a[n];
    for(int i=0; i<n; i++) scanf("%d", &a[i]);
    quicksort(a, 0, n-1, n, m);
    for(int i=0; i<n; i++) printf("%d%s", a[i], " ");
    return 0;
}